#include <iostream>

#include "blockchain.h"
using namespace Blockchain;

int Block::count_id_block = 0;

int main()
{
  Transaction *trans = new Transaction("123", "321", 5),
              *trans_1 = new Transaction("456", "654", 5),
              *trans_2 = new Transaction("789", "987", 5);

  std::vector<Transaction> t_lst = {*trans, *trans_1, *trans_2};

  // trans->print();
  Block block_1, block_2(t_lst);
  block_1.print();
  block_2.print();

  delete trans;
  delete trans_1;
  delete trans_2;

  return 0;
}
