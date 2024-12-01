#include "blockchain.h"

Blockchain::Block::Block(const std::vector<Transaction>& t_actions_lst_argv): t_actions_lst(t_actions_lst_argv) {}

void Blockchain::Block::print() const {
    std::cout << "Block " << id_block << " info:" << std::endl;
    std::cout << "Previous block id: " << id_prev << std::endl;
    std::cout << "Transactions:" << std::endl << std::endl;
    for (auto &transaction : t_actions_lst) {
        transaction.print();
        std::cout << std::endl;
    }
}
