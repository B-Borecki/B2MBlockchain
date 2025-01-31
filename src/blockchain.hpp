#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <vector>

namespace Blockchain
{

	class Transaction
	{
	private:
		std::string sender_id;
		std::string receiver_id;
		double amount;

	public:
		Transaction(std::string sender, std::string receiver, double amt);
		void print() const;
		std::string hash();
	};

	class Block
	{
	public:
		std::string id_block;
		std::string id_prev;
		int nonce;
		std::vector<Transaction> t_actions_lst;
		Block(const std::vector<Transaction> &t_actions_lst_argv);
		void print() const;
	};

	class Blockchain
	{
	private:
		std::vector<Block> chain;

	public:
		Blockchain();
		void add_block(Block block);
		void print_chain() const;
		std::string id_last();
	};

	class Web
	{
	public:
		std::vector<Transaction> mempool;
		std::vector<Block> block_lst;
	};

	class Node
	{
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

	class Miner : private Node
	{
	public:
		Miner(Web &web, std::mutex &m, std::condition_variable &c, Blockchain *chain);
		void mine();
	};

	class Emitter : private Node
	{
	public:
		Emitter(Web &web, std::mutex &m, std::condition_variable &c);
		void emit(std::string id_sender, std::string id_receiver, double amount);
	};

	namespace merkle_tree
	{
		class Tree
		{
		private:
			std::vector<std::string> hashes;
			Node merkle_root;

		public:
			Node generate_root(Block &block, std::vector<std::string> &hashes);
			void generate_tree(std::vector<std::string> &hashes);
			bool merkle_proof(Block &block, std::string &hash_verify);
		};

		class Node
		{
			std::string left;
			std::string right;
			std::string concat;

			Node(std::string &hash_left, Transaction &hash_right);
		};

		class Leaf
		{
			std::string hash_trans;

			Leaf(std::string &hash_trans);
		};

	} // namespace merkle_tree
}
