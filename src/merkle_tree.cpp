#include "blockchain.hpp"
#include <cstddef>
#include <vector>
namespace Blockchain{
    namespace merkle_tree {
        std::string m_hash(std::string left_hash, std::string right_hash){
            std::string hash;
           	std::stringstream concat;
            concat << left_hash + right_hash;
           	CryptoPP::SHA256 sha256;
           	CryptoPP::StringSource foo(concat.str(), true,
          		new CryptoPP::HashFilter(sha256,
         			new CryptoPP::Base64Encoder(
            				new CryptoPP::StringSink(hash))));
            return hash;
        }

        std::vector<std::string> hash_transactions(std::vector<Transaction> &transactions) {
            std::vector<std::string> merkle_hashes;
            for (auto &t : transactions) {
                merkle_hashes.push_back(t.hash());
            }
            return merkle_hashes;
        }

        void Tree::generate_merkle_tree(std::vector<Transaction> &transactions){
            merkle_hashes = hash_transactions(transactions);

            size_t size = merkle_hashes.size();

            size_t i = 0;
            while(size > 1){
                for(size_t j = i; j < i + size; j+=2){
                    merkle_hashes.push_back(m_hash(merkle_hashes[j], merkle_hashes[j+1]));
                }
                if(size % 2 == 1){
                    merkle_hashes.push_back(merkle_hashes.back());
                }
                size /= 2;
            }
            // 0 1 2 3 4 5 6 7 -> 00 11 22 33
        }

        void Tree::add_transactions(std::vector<Transaction> &transactions){
            merkle_hashes.clear();
            generate_merkle_tree(transactions);
            merkle_root = merkle_hashes.back();
        }

        Tree::Tree(std::vector<Transaction> &transactions){
            add_transactions(transactions);
        }



    } // namespace merkle_tree
}
