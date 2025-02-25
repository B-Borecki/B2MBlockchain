#include "blockchain.hpp"

namespace blockchain {
    Emitter::Emitter(Web &web, std::mutex &m, std::condition_variable &c)
    	: Node(web, m, c) {}

    void Emitter::emit(
    		std::string id_sender, std::string id_receiver, double amount) {
    	std::this_thread::sleep_for(std::chrono::seconds(1));
    	Transaction transaction(id_sender, id_receiver, amount);

    	{
    		std::lock_guard<std::mutex> lock(mtx);
    		mempool.push_back(transaction);
    	}

    	cv.notify_all();
    }
}
