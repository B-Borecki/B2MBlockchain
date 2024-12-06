#include "blockchain.hpp"

Blockchain::Blockchain::Blockchain() {
	id_first = 0;
	std::vector<Transaction> first_tran = {};
	Block genesis_block(first_tran);
	genesis_block.id_prev = -1;
	genesis_block.id_block = 0;
	chain.push_back(genesis_block);
}

void Blockchain::Blockchain::add_block(Block new_block) {
	new_block.id_prev = chain.back().id_block;
	chain.push_back(new_block);
}

void Blockchain::Blockchain::print_chain() const {
	for (const auto &block : chain) {
		block.print();
		std::cout << "---------------------" << std::endl;
	}
}