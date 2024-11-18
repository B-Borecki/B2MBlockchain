#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Blockchain
{

  class Transaction
  {
  private:
    std::string sender_id;
    std::string receiver_id;
    double amount;

  public:
    Transaction(std::string sender, std::string receiver, double amt);
    void print() const;
  };

  class Block
  {
  private:
    static int count_id_block;

  public:
    int id_block;
    int id_prev;
    std::vector<Transaction> t_actions_lst;

    Block();
    Block(std::vector<Transaction> &t_actions_lst_argv);

    void print();
  };
}