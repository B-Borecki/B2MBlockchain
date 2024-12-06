#include "blockchain.hpp"
#include <condition_variable>
#include <mutex>
#include <thread>

Blockchain::Miner::Miner(Web &web, std::mutex &m, std::condition_variable &c)
		: mempool(web.mempool), block_lst(web.block_lst), mtx(m), cv(c) {}

void Blockchain::Miner::mine() {
	// hard work
	std::this_thread::sleep_for(std::chrono::seconds(2));

	// waiting for enough transactions
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [&] { return mempool.size() >= 4; });

	// create Transaction vector
	std::vector<Transaction> trans_lst;
	for (int i = 0; i < 4; i++) {
		trans_lst.push_back(mempool[i]);
	}

	// create block
	Block block(trans_lst);
	block_lst.push_back(block);
}