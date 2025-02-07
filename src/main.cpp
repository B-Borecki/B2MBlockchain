#include "blockchain.hpp"


void print_test_m(){
    std::vector<Blockchain::Transaction> lst = {
    Blockchain::Transaction("User1", "User2", 50.0),
    Blockchain::Transaction("User3", "User4", 75.5),
    Blockchain::Transaction("User5", "User6", 120.0),
    Blockchain::Transaction("User7", "User8", 30.0),
    Blockchain::Transaction("User9", "User10", 200.0),
    Blockchain::Transaction("User11", "User12", 15.0),
    Blockchain::Transaction("User13", "User14", 60.0),
    Blockchain::Transaction("User15", "User16", 90.0),
    Blockchain::Transaction("User17", "User18", 45.0),
    };

    Blockchain::Block block(lst);

    Blockchain::merkle_tree::Tree tree(block.t_actions_lst);

    tree.print_hashes();
    Blockchain::merkle_tree::proof_pair result = tree.merkle_proof("XxUO0gMRxW7Xe3vi6zsrD3qu8UTuAF4Nd2TBTJgnYrE=");

    std::cout << "Returned hashes: " << std::endl;
    for(auto &l : result.proof){
        std::cout << l << std::endl;
    }
    std::cout << "Directions: " << std::endl;
    for(auto &l : result.direction){
        std::cout << l << std::endl;
    }

    std::cout << "Merkle root:          " << tree.merkle_root << std::endl;
    std::cout << "Root from validation: " <<Blockchain::merkle_tree::validate_merkle_proof(result) << std::endl;

}

int main() {
	std::mutex mtx;
	std::condition_variable cv;
	Blockchain::Blockchain blockchain;
	Blockchain::Web web;

	// let the miner mine
	Blockchain::Miner miner1(web, mtx, cv, &blockchain);
	std::thread miner_thread(&Blockchain::Miner::mine, &miner1);
	Blockchain::Emitter emitter1(web, mtx, cv);

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
	Blockchain::Block new_block = web.block_lst[0];
	blockchain.add_block(new_block);
	blockchain.print_chain();

	print_test_m();
	return 0;
}
