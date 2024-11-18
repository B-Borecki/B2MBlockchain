#include "blockchain.h"

Blockchain::Transaction::Transaction(std::string sender, std::string receiver,
                                     double amt)
    : sender_id(sender), receiver_id(receiver), amount(amt) {}

void Blockchain::Transaction::print() const
{
  std::cout << "Sender: " << sender_id << "\nReceiver: " << receiver_id
            << "\nAmount: " << amount << std::endl;
}
