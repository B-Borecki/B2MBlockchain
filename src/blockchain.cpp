#include "blockchain.h"

Blockchain::Blockchain::Blockchain() {
    id_first = 0;
    chain.push_back(create_first_block());
}

Blockchain::Block Blockchain::Blockchain::create_first_block() {
    std::vector<Transaction> first_tran = { Transaction("System", "User", 1000.0) };
    Block genesis_block(0, -1, first_tran); 
    return genesis_block;
}

void Blockchain::Blockchain::add_block(const std::vector<Transaction>& tran_list) {
    int prev_block_id = chain.back().id_block; 
    Block new_block(chain.size(), prev_block_id, tran_list);
    chain.push_back(new_block);
}

void Blockchain::Blockchain::print_chain() const {
    for (const auto& block : chain) {
        block.print();
        std::cout << "---------------------" << std::endl;
    }
}