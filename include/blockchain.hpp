#pragma once

#include "proto/blockchain.pb.h"
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <cryptlib.h>
#include <sha.h>
#include <filters.h>
#include <base64.h>
#include <thread>
#include <unordered_map>

namespace blockchain
{
    // Blockchain subclasses
	class Transaction
	{
	private:
		BlockchainProto::Transaction transaction;

	public:
		Transaction(std::string sender, std::string receiver, double amt);
		void print() const;
		std::string hash();
		BlockchainProto::Transaction get_proto();
		void set_sender_id(std::string sender);
		void set_receiver_id(std::string receiver);
		void set_amount(double amount);
		std::string sender_id() const;
		std::string receiver_id() const;
		double amount() const;
	};

	class Block
	{
	private:

	BlockchainProto::Block block;

	public:
		Block(const std::vector<Transaction> &t_actions_lst_argv);
		std::vector<Transaction> t_actions_lst;
		void print() const;
		BlockchainProto::Block get_proto();
		void set_id_prev(std::string id);
		void set_id_block(std::string id);
		void set_nonce(int nonce);
		std::string id_prev() const;
		std::string id_block() const;
		int nonce() const;
	};

	class Blockchain
	{
	private:
		BlockchainProto::Blockchain blockchain;
		std::vector<Block> chain;

	public:
		Blockchain();
		void add_block(Block block);
		void print_chain() const;
		std::string id_last();
	};

	// Nodes classes
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

	// Merkle Tree
	namespace merkle_tree
	{
	    typedef std::vector<std::string> vec1dstr;
	    typedef std::vector<std::vector<std::string>> vec2dstr;


		struct proof_pair{
		    vec1dstr proof;
			vec1dstr direction;
		};

		class Tree
		{
    		private:
                std::unordered_map<std::string, size_t> transactions_hash_map;
    			vec2dstr merkle_hashes;

    			vec1dstr hash_transactions(std::vector<Transaction> &transactions);

    		public:
    			std::string merkle_root;

    			Tree(std::vector<Transaction> &transactions);
    			void generate_merkle_tree(std::vector<Transaction> &transactions);

                void add_transactions(std::vector<Transaction> &transactions);
    			proof_pair merkle_proof(Transaction &transaction);

                void print_hashes();
        };
        std::string m_hash(std::string left_hash, std::string right_hash);
		std::string validate_merkle_proof(proof_pair result);
	}
}
