#include "blockchain.hpp"

Blockchain::Transaction::Transaction(std::string sender, std::string receiver, double amt)
{
	set_sender_id(sender);
	set_receiver_id(receiver);
	set_amount(amt);
}

void Blockchain::Transaction::print() const
{
	std::cout << "Sender: " << sender_id() << "\nReceiver: " << receiver_id() << "\nAmount: " << amount()
			  << std::endl;
}

std::string Blockchain::Transaction::hash()
{
	std::string hash;
	std::stringstream ss;
	ss << sender_id() << "#" << receiver_id() << "#" << amount();
	CryptoPP::SHA256 sha256;
	CryptoPP::StringSource foo(ss.str(), true,
		new CryptoPP::HashFilter(sha256,
			new CryptoPP::Base64Encoder(
				new CryptoPP::StringSink(hash))));
	return hash;
}

BlockchainProto::Transaction Blockchain::Transaction::get_proto()
{
	return transaction;
}

void Blockchain::Transaction::set_sender_id(std::string sender)
{
	transaction.set_sender_id(sender);
}

void Blockchain::Transaction::set_receiver_id(std::string receiver)
{
	transaction.set_receiver_id(receiver);
}

void Blockchain::Transaction::set_amount(double amount)
{
	transaction.set_amount(amount);
}

std::string Blockchain::Transaction::sender_id() const
{
	return transaction.sender_id();
}

std::string Blockchain::Transaction::receiver_id() const
{
	return transaction.receiver_id();
}

double Blockchain::Transaction::amount() const
{
	return transaction.amount();
}
