cmake_minimum_required(VERSION 3.10)

project(B2MBlockchain)

find_package(Protobuf REQUIRED)
find_package(absl REQUIRED)

set(PROTO blockchain.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO})

add_executable(blockchain
    main.cpp
    transaction.cpp
    block.cpp
    blockchain.cpp
    miner.cpp
    emitter.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

include_directories(/usr/include/cryptopp)
link_directories(/usr/lib/libcryptopp.so)
target_link_libraries(blockchain PUBLIC cryptopp protobuf::libprotobuf absl::log_internal_check_op)