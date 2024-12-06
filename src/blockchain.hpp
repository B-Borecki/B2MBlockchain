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
	};

	class Block {
	public:
		int id_block;
		int id_prev;
		std::vector<Transaction> t_actions_lst;
		Block(const std::vector<Transaction> &t_actions_lst_argv);
		void print() const;
	};

	class Blockchain {
	private:
		int id_first;
		std::vector<Block> chain;

	public:
		Blockchain();
		void add_block(Block block);
		void print_chain() const;
	};

	class Web {
	public:
		std::vector<Transaction> mempool;
		std::vector<Block> block_lst;
	};

	class Miner {
	private:
		int id_miner;
		std::vector<Transaction> &mempool;
		std::vector<Block> &block_lst;
		std::mutex &mtx;
		std::condition_variable &cv;

	public:
		Miner(Web &web, std::mutex &m, std::condition_variable &c);
		void mine();
	};

	class Emitter {
	private:
		int id_emitter;
		std::vector<Transaction> &mempool;
		std::mutex &mtx;
		std::condition_variable &cv;

	public:
		Emitter(Web &web, std::mutex &m, std::condition_variable &c);
		void emit(std::string id_sender, std::string id_receiver, double amount);
	};
} // namespace Blockchain
