#include "blockchain.hpp"
#include <sstream>
#include <cryptlib.h>
#include <sha.h>
#include <filters.h>
#include <base64.h>

Blockchain::Transaction::Transaction(std::string sender, std::string receiver, double amt)
		: sender_id(sender), receiver_id(receiver), amount(amt) {}

void Blockchain::Transaction::sign(const CryptoPP::RSA::PrivateKey &privateKey) {
    std::string digest = hash();
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::RSASS<CryptoPP::PKCS1v15, CryptoPP::SHA256>::Signer signer(privateKey);
    CryptoPP::StringSource ss(digest, true,
        new CryptoPP::SignerFilter(rng, signer,
            new CryptoPP::StringSink(signature)));
}

bool Blockchain::Transaction::validate(const CryptoPP::RSA::PublicKey &publicKey) const {
    CryptoPP::RSASS<CryptoPP::PKCS1v15, CryptoPP::SHA256>::Verifier verifier(publicKey);
    bool result = false;
    CryptoPP::StringSource ss(signature + hash(), true,
        new CryptoPP::SignatureVerificationFilter(verifier,
            new CryptoPP::ArraySink(reinterpret_cast<CryptoPP::byte*>(&result), sizeof(result))));
    return result;
}

void Blockchain::Transaction::print() const {
	std::cout << "Sender: " << sender_id << "\nReceiver: " << receiver_id << "\nAmount: " << amount
						<< std::endl;
}

std::string Blockchain::Transaction::hash() const {
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