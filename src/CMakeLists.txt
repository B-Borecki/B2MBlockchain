cmake_minimum_required(VERSION 3.10)

project(B2MBlockchain)


add_executable(blockchain
    main.cpp
    transaction.cpp
    block.cpp
    blockchain.cpp
    miner.cpp
    emitter.cpp
)

include_directories(/usr/include/cryptopp)
link_directories(/usr/lib/libcryptopp.so)
target_link_libraries(blockchain cryptopp)
