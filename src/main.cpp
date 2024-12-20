#include "blockchain.hpp"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

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

	return 0;
}