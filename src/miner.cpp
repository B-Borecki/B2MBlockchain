#include "blockchain.h"

Blockchain::Miner::Miner(Web web) trans_lst(web.trans_lst), block_lst(web.block_lst) {}