#include "blockchain.hpp"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <map>
#include <rsa.h>
#include <osrng.h>

int main() {
    std::mutex mtx;
    std::condition_variable cv;
    Blockchain::Blockchain blockchain;
    Blockchain::Web web;
    // private and public keys
    std::map<std::string, CryptoPP::RSA::PrivateKey> privateKeys;
    std::map<std::string, CryptoPP::RSA::PublicKey> publicKeys;
    CryptoPP::AutoSeededRandomPool rng;
    std::vector<std::string> users = {"User1", "User2", "User3", "User4"};
    for (const auto &user : users) {
        CryptoPP::RSA::PrivateKey privateKey;
        CryptoPP::RSA::PublicKey publicKey;
        privateKey.GenerateRandomWithKeySize(rng, 2048);
        publicKey.AssignFrom(privateKey);
        privateKeys[user] = privateKey;
        publicKeys[user] = publicKey;
    }
	// launching miner
    Blockchain::Miner miner1(web, mtx, cv, &blockchain);
    std::thread miner_thread(&Blockchain::Miner::mine, &miner1);
    Blockchain::Emitter emitter1(web, mtx, cv);
    // emitting transactions
    std::vector<std::thread> threads;
    threads.emplace_back([&]() {
        Blockchain::Transaction tx("User1", "User2", 50.0);
        tx.sign(privateKeys["User1"]);
        if (miner1.validate_transaction(tx, publicKeys["User1"])) {
            std::lock_guard<std::mutex> lock(mtx);
            web.mempool.push_back(tx);
            cv.notify_all();
        } else {
            std::cerr << "Invalid transaction from User1 to User2!" << std::endl;
        }
    });
    threads.emplace_back([&]() {
        Blockchain::Transaction tx("User2", "User1", 30.0);
        tx.sign(privateKeys["User2"]);
        
        if (miner1.validate_transaction(tx, publicKeys["User2"])) {
            std::lock_guard<std::mutex> lock(mtx);
            web.mempool.push_back(tx);
            cv.notify_all();
        } else {
            std::cerr << "Invalid transaction from User2 to User1!" << std::endl;
        }
    });
    threads.emplace_back([&]() {
        Blockchain::Transaction tx("User3", "User2", 20.0);
        tx.sign(privateKeys["User3"]);
        if (miner1.validate_transaction(tx, publicKeys["User3"])) {
            std::lock_guard<std::mutex> lock(mtx);
            web.mempool.push_back(tx);
            cv.notify_all();
        } else {
            std::cerr << "Invalid transaction from User3 to User2!" << std::endl;
        }
    });
    threads.emplace_back([&]() {
        Blockchain::Transaction tx("User1", "User4", 10.0);
        tx.sign(privateKeys["User1"]);
        
        if (miner1.validate_transaction(tx, publicKeys["User1"])) {
            std::lock_guard<std::mutex> lock(mtx);
            web.mempool.push_back(tx);
            cv.notify_all();
        } else {
            std::cerr << "Invalid transaction from User1 to User4!" << std::endl;
        }
    });
    // waiting for threads to end
    for (auto &thread : threads) {
        thread.join();
    }
    miner_thread.join();
    if (!web.block_lst.empty()) {
        Blockchain::Block new_block = web.block_lst[0];
        blockchain.add_block(new_block);
        blockchain.print_chain();
    } else {
        std::cerr << "No block was mined!" << std::endl;
    }
    return 0;
}