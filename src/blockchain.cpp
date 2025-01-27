#include "blockchain.hpp"

Blockchain::Blockchain::Blockchain() {
	std::vector<Transaction> first_tran = {};
	Block genesis_block(first_tran);
	genesis_block.set_id_prev("-1");
	genesis_block.set_id_block("0");
	genesis_block.set_nonce(0);

	chain.push_back(genesis_block);
	*blockchain.add_chain() = genesis_block.get_proto();
}

void Blockchain::Blockchain::add_block(Block new_block) {
	new_block.id_prev() = chain.back().id_block();
	chain.push_back(new_block);
	*blockchain.add_chain() = new_block.get_proto();
}

void Blockchain::Blockchain::print_chain() const {
	for (const auto &block : chain) {
		block.print();
		std::cout << "---------------------" << std::endl;
	}
}
std::string Blockchain::Blockchain::id_last() {
	return chain.back().id_block();
}