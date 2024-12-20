#include "blockchain.hpp"
#include <sstream>
#include <cryptlib.h>
#include <sha.h>
#include <filters.h>
#include <base64.h>

Blockchain::Transaction::Transaction(std::string sender, std::string receiver, double amt)
		: sender_id(sender), receiver_id(receiver), amount(amt) {}

void Blockchain::Transaction::print() const {
	std::cout << "Sender: " << sender_id << "\nReceiver: " << receiver_id << "\nAmount: " << amount
						<< std::endl;
}

std::string Blockchain::Transaction::hash() {
	std::string hash;
 	std::stringstream ss;
	ss << sender_id << receiver_id << amount;
    CryptoPP::SHA256 sha256;
    CryptoPP::StringSource foo(ss.str(), true,
    new CryptoPP::HashFilter(sha256,
      new CryptoPP::Base64Encoder (
         new CryptoPP::StringSink(hash))));
    return hash;
}