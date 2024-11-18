#include "blockchain.h"

Blockchain::Block::Block() : id_block(0), id_prev(-1) {}

Blockchain::Block::Block(std::vector<Transaction> &t_actions_lst_argv)
    : t_actions_lst(t_actions_lst_argv),
      id_block(++count_id_block) {}

void Blockchain::Block::print()
{
    std::cout << "Block " << id_block << " info:" << std::endl;
    std::cout << "Previous id: " << id_prev << std::endl;
    std::cout << "Transactions:" << std::endl
              << std::endl;

    for (auto &transaction : t_actions_lst)
    {
        transaction.print();
        std::cout << std::endl;
    }
}