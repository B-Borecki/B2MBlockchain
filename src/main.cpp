#include "blockchain.hpp"


void print_test_m(){
    std::vector<blockchain::Transaction> lst = {
    blockchain::Transaction("User1", "User2", 50.0),
    blockchain::Transaction("User3", "User4", 75.5),
    blockchain::Transaction("User5", "User6", 120.0),
    blockchain::Transaction("User7", "User8", 30.0),
    blockchain::Transaction("User9", "User10", 200.0),
    blockchain::Transaction("User11", "User12", 15.0),
    blockchain::Transaction("User13", "User14", 60.0),
    blockchain::Transaction("User15", "User16", 90.0),
    blockchain::Transaction("User17", "User18", 45.0),
    };

    blockchain::Block block(lst);

    blockchain::merkle_tree::Tree tree(block.t_actions_lst);

    tree.print_hashes();
    blockchain::merkle_tree::proof_pair result = tree.merkle_proof("XxUO0gMRxW7Xe3vi6zsrD3qu8UTuAF4Nd2TBTJgnYrE=");

    std::cout << "Returned hashes: " << std::endl;
    for(auto &l : result.proof){
        std::cout << l << std::endl;
    }
    std::cout << "Directions: " << std::endl;
    for(auto &l : result.direction){
        std::cout << l << std::endl;
    }

    std::cout << "Merkle root:          " << tree.merkle_root << std::endl;
    std::cout << "Root from validation: " <<blockchain::merkle_tree::validate_merkle_proof(result) << std::endl;

}

int main() {
	std::mutex mtx;
	std::condition_variable cv;
	blockchain::Blockchain blockchain_;
	blockchain::Web web;

	// let the miner mine
	blockchain::Miner miner1(web, mtx, cv, &blockchain_);
	std::thread miner_thread(&blockchain::Miner::mine, &miner1);
	blockchain::Emitter emitter1(web, mtx, cv);

	// creating threads to send transactions using emitter
	std::vector<std::thread> threads;
	threads.emplace_back([&emitter1]() { emitter1.emit("User1", "User2", 50.0); });
	threads.emplace_back([&emitter1]() { emitter1.emit("User2", "User1", 30.0); });
	threads.emplace_back([&emitter1]() { emitter1.emit("User3", "User2", 20.0); });
	threads.emplace_back([&emitter1]() { emitter1.emit("User1", "User4", 10.0); });

	// join all threads
	for (auto &thread : threads) {
		thread.join();
	}

	miner_thread.join();

	// adding to blockchain the block created by miner1
	blockchain::Block new_block = web.block_lst[0];
	blockchain_.add_block(new_block);
	blockchain_.print_chain();

	print_test_m();
	return 0;
}
