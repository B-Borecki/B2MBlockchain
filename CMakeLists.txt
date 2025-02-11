cmake_minimum_required(VERSION 3.10)

project(B2MBlockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
    cryptopp
    GIT_REPOSITORY https://github.com/weidai11/cryptopp.git
)

FetchContent_MakeAvailable(cryptopp)

find_package(Protobuf REQUIRED)
find_package(absl REQUIRED)

protobuf_generate_cpp(PROTO_C PROTO_H blockchain.proto)

add_executable(blockchain
    src/main.cpp
    src/b-core/transaction.cpp
    src/b-core/block.cpp
    src/b-core/blockchain.cpp
    src/b-nodes/miner.cpp
    src/b-nodes/emitter.cpp
    src/merkle_tree.cpp
    ${PROTO_C}
    ${PROTO_H}
)

target_link_libraries(blockchain PUBLIC cryptopp protobuf::libprotobuf absl::log_internal_check_op)
target_include_directories(blockchain PUBLIC include ${cryptopp_SOURCE_DIR})
