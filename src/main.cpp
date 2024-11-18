#include "blockchain.h"

int main() {
    Blockchain::Blockchain blockchain;
    std::vector<Blockchain::Transaction> transactions1 = {
        Blockchain::Transaction("User1", "User2", 50.0),
        Blockchain::Transaction("User2", "User1", 30.0)
    };
    std::vector<Blockchain::Transaction> transactions2 = {
        Blockchain::Transaction("User3", "User2", 20.0),
        Blockchain::Transaction("User1", "User4", 10.0)
    };
    blockchain.add_block(transactions1);
    blockchain.add_block(transactions2);
    blockchain.print_chain();
    return 0;
}
