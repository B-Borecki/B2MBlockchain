#include "blockchain.h"

Transaction::Transaction(std::string sender, std::string receiver, double amt) : sender_id(sender), receiver_id(receiver), amount(amt) {}

void Transaction::print() const {
    std::cout << "Sender: " << sender_id << "\nReceiver: " << receiver_id << "\nAmount: " << amount << std::endl;
}
