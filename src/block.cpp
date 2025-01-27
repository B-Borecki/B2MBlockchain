#include "blockchain.hpp"

Blockchain::Block::Block(const std::vector<Transaction> &t_actions_lst_argv) {
	for (auto trans : t_actions_lst_argv) {
		*block.add_t_actions_lst() = trans.get_proto();
		t_actions_lst.push_back(trans);
	}
}

void Blockchain::Block::print() const {
	std::cout << "Block " << id_block() << std::endl;
	std::cout << "Previous block id: " << id_prev() << std::endl;
	std::cout << "Transactions:\n\n";
	for (auto &transaction : t_actions_lst) {
		transaction.print();
		std::cout << std::endl;
	}
	std::cout << "Nonce: " << nonce() << std::endl;
}

BlockchainProto::Block Blockchain::Block::get_proto() {
    return block;
}

void Blockchain::Block::set_id_prev(std::string id) {
	block.set_id_prev(id);
}

void Blockchain::Block::set_id_block(std::string id) {
	block.set_id_block(id);
}

void Blockchain::Block::set_nonce(int nonce) {
	block.set_nonce(nonce);
}

std::string Blockchain::Block::id_prev() const{
	return block.id_prev();
}

std::string Blockchain::Block::id_block() const{
	return block.id_block();
}

int Blockchain::Block::nonce() const{
	return block.nonce();
}