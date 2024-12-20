#include "blockchain.hpp"
#include <string>
#include <sstream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <cryptlib.h>
#include <sha.h>
#include <filters.h>
#include <base64.h>

Blockchain::Miner::Miner(Web &web, std::mutex &m, std::condition_variable &c, Blockchain *chain)
	: Node(web, m, c, chain) {}

void Blockchain::Miner::mine() {
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
	block.id_prev = blockchain->id_last();

	int nonce = 0;
  std::string hash;
 	std::stringstream ss;
	do {
		hash = "";
		nonce++;
		ss << block.id_prev;
		auto trans = block.t_actions_lst;
		for (int i = 0; i < trans.size(); i++) {
			ss << trans[i].hash();
		}
		ss << nonce;
    CryptoPP::SHA256 sha256;
    CryptoPP::StringSource foo(ss.str(), true,
    new CryptoPP::HashFilter(sha256,
      new CryptoPP::Base64Encoder (
         new CryptoPP::StringSink(hash))));
    ss.clear();
	} while (hash.substr(0, 2) != "00");

	block.id_block = hash;
	block.nonce = nonce;

	block_lst.push_back(block);
}
