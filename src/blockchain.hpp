#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <vector>

namespace Blockchain {

	class Transaction {
	private:
		std::string sender_id;
		std::string receiver_id;
		double amount;

	public:
		Transaction(std::string sender, std::string receiver, double amt);
		void print() const;
		std::string hash();
	};

	class Block {
	public:
		std::string id_block;
		std::string id_prev;
		int nonce;
		std::vector<Transaction> t_actions_lst;
		Block(const std::vector<Transaction> &t_actions_lst_argv);
		void print() const;
	};

	class Blockchain {
	private:
		std::vector<Block> chain;

	public:
		Blockchain();
		void add_block(Block block);
		void print_chain() const;
		std::string id_last();
	};

	class Web {
	public:
		std::vector<Transaction> mempool;
		std::vector<Block> block_lst;
	};

	class Node {
	protected:
		int id;
		std::vector<Transaction> &mempool;
		std::vector<Block> &block_lst;
		std::mutex &mtx;
		std::condition_variable &cv;
		Blockchain *blockchain;
	public:
		Node(Web &web, std::mutex &m, std::condition_variable &c, Blockchain *chain)
			: mempool(web.mempool), block_lst(web.block_lst), mtx(m), cv(c), blockchain(chain) {}
		Node(Web &web, std::mutex &m, std::condition_variable &c)
					: mempool(web.mempool), block_lst(web.block_lst), mtx(m), cv(c) {}
	};

	class Miner : private Node {
	public:
		Miner(Web &web, std::mutex &m, std::condition_variable &c, Blockchain *chain);
		void mine();
	};

	class Emitter : private Node {
	public:
		Emitter(Web &web, std::mutex &m, std::condition_variable &c);
		void emit(std::string id_sender, std::string id_receiver, double amount);
	};
}
