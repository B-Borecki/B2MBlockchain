#include "blockchain.h"

Blockchain::Block::Block(int id, int prev, const std::vector<Transaction>& t_actions_lst_argv): id_block(id), id_prev(prev), t_actions_lst(t_actions_lst_argv) {}

void Blockchain::Block::print() const {
    std::cout << "Block " << id_block << " info:" << std::endl;
    std::cout << "Previous id: " << id_prev << std::endl;
    std::cout << "Transactions:" << std::endl << std::endl;
    for (auto &transaction : t_actions_lst) {
        transaction.print();
        std::cout << std::endl;
    }
}
