#include "blockchain.hpp"
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <cryptlib.h>
#include <sha.h>
#include <filters.h>
#include <base64.h>

Blockchain::Miner::Miner(Web &web, std::mutex &m, std::condition_variable &c)
	: Node(web, m, c) {}

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
	std::string input = "haszuj mje";
    CryptoPP::SHA256 hash;
    std::string hasz;
    CryptoPP::StringSource foo(input, true,
    new CryptoPP::HashFilter(hash,
      new CryptoPP::Base64Encoder (
         new CryptoPP::StringSink(hasz))));

	// create block
	Block block(trans_lst);
	block_lst.push_back(block);
}
