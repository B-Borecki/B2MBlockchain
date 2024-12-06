#include "blockchain.hpp"
#include <condition_variable>
#include <mutex>
#include <thread>

int main() {
	std::mutex mtx;
	std::condition_variable cv;
	Blockchain::Blockchain blockchain;
	Blockchain::Web web;

	// let the miner mine
	Blockchain::Miner miner1(web, mtx, cv);
	std::thread miner_thread(&Blockchain::Miner::mine, &miner1);

	// to działanie powinien implementować emitter
	// sending transactions to nodes
	web.mempool.push_back(Blockchain::Transaction("User1", "User2", 50.0));
	web.mempool.push_back(Blockchain::Transaction("User2", "User1", 30.0));
	web.mempool.push_back(Blockchain::Transaction("User3", "User2", 20.0));
	web.mempool.push_back(Blockchain::Transaction("User1", "User4", 10.0));

	miner_thread.join();

	// adding to blockchain the block created by miner1
	Blockchain::Block new_block = web.block_lst[0];
	blockchain.add_block(new_block);
	blockchain.print_chain();

	return 0;
}