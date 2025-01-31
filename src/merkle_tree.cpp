#include "blockchain.hpp"

namespace Blockchain::merkle_tree {
	Leaf(std::string &hash_trans) : hash_trans(hash_trans) {}

	Node(std::string &hash_left, Transaction &hash_right)
			: left(hash_left), right(hash_right) {
		concat = left + right;
	}

	void generate_root(Block &block, std::vector<std::string> &hashes) {
		for (auto &transaction : block.t_actions_lst) {
			hashes.push_back(transaction.hash());
		}
	}

	bool merkle_proof(Block &block, std::string &hash_verify) {}
} // namespace Blockchain::merkle_tree
