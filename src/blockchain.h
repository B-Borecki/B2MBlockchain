#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <string>
#include <iostream>

class Transaction {
private:
    std::string sender_id;
    std::string receiver_id;
    double amount;
public:
    Transaction(std::string sender, std::string receiver, double amt);
    void print() const;
};

#endif
