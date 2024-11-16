#include <iostream>
#include "blockchain.h"

int main() {
    Transaction* trans = new Transaction("123", "321", 5);
    trans->print();

    delete trans;
    return 0;
}
