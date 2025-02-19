#include "blockchain.hpp"

namespace blockchain {
    namespace merkle_tree {
        std::string m_hash(std::string left_hash, std::string right_hash){
            std::string hash;
           	std::stringstream concat;
            concat << left_hash + right_hash;
           	CryptoPP::SHA256 sha256;
           	CryptoPP::StringSource foo(concat.str(), true,
          		new CryptoPP::HashFilter(sha256,
         			new CryptoPP::Base64Encoder(
            				new CryptoPP::StringSink(hash), false)));
            return hash;
        }

        vec1dstr Tree::hash_transactions(std::vector<Transaction> &transactions) {
            vec1dstr merkle_hashes;
            for (auto &t : transactions) {
                merkle_hashes.push_back(t.hash());
            }
            return merkle_hashes;
        }

        void Tree::generate_merkle_tree(std::vector<Transaction> &transactions){
            vec1dstr hashed_transactions = hash_transactions(transactions);
            merkle_hashes.push_back(hashed_transactions);
            size_t size = merkle_hashes[0].size();

            for (size_t i=0; i<size; i++) {
                transactions_hash_map[merkle_hashes[0][i]] = i;
            }

            if (size == 0) return;

            while (size > 1) {
                vec1dstr row;
                // Copying the last element if the length is odd
                if (size % 2 == 1) {
                    merkle_hashes.back().push_back(merkle_hashes.back().back());
                    size++;
                }

                // Combining elements into pairs
                for (size_t j = 0; j + 1 < size; j += 2) {
                    row.push_back(m_hash(merkle_hashes.back()[j], merkle_hashes.back()[j + 1]));
                }
                merkle_hashes.push_back(row);
                size /= 2;
            }
        }

        void Tree::add_transactions(std::vector<Transaction> &transactions){
            merkle_hashes.clear();
            generate_merkle_tree(transactions);

            if (merkle_hashes.back().size() == 1)
                merkle_root = merkle_hashes.back().back();
            else{
                std::cout << "Wrong created merkle tree, size = " << merkle_hashes.back().size() << std::endl;
                for(auto &l : merkle_hashes.back()){
                    std::cout<< l << std::endl;
                }
            }
        }

        Tree::Tree(std::vector<Transaction> &transactions){
            add_transactions(transactions);
        }

        // Creating merkle proof in O(log n) time
        proof_pair Tree::merkle_proof(Transaction &transaction){
            proof_pair result;
            std::string hash = transaction.hash();

            size_t size = merkle_hashes[0].size(), index;
            size_t levels = merkle_hashes.size();

            // Finding the index of the transaction in O(1) time
            auto it = transactions_hash_map.find(hash);
            if(it == transactions_hash_map.end()){
                std::cout << "Hash not found" << std::endl;
                return result;
            }
            else{
                // Setting the index to the iterator value corresponding
                // to the transaction's index at the last level
                index = it->second;
            }

            result.proof.push_back(merkle_hashes[0][index]);
            result.direction.push_back(index % 2 == 0 ? "Left" : "Right");

            for(size_t i = 0; i < levels-1; i++){
                // Brother of the parent node at the previous index
                int bro = index % 2 == 0 ? index + 1 : index - 1;

                result.direction.push_back(bro % 2 == 0 ? "Left" : "Right");
                result.proof.push_back(merkle_hashes[i][bro]);
                index = index / 2;
            }
            return result;
        }

        std::string validate_merkle_proof(proof_pair result){
            std::string root = result.proof[0];
            for(size_t i = 1; i < result.proof.size(); i++){
                if(result.direction[i] == "Left")
                    root = m_hash(result.proof[i], root);
                else
                    root = m_hash(root, result.proof[i]);
            }
            return root;
        }

        void Tree::print_hashes(){
            size_t high = merkle_hashes.size() - 1;

            std::cout << "Merkle tree: " << std::endl;
            for(auto &level : merkle_hashes){
                std::cout << "Level: " << high << std::endl;
                std::cout << "Size: " << level.size() << std::endl;
                for(auto &h : level)
                    std::cout << h << std::endl;
                high--;
            }

            std::cout << "Height of tree: " << merkle_hashes.size() << std::endl;
        }

    } // namespace merkle_tree
}
