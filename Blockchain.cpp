#include <ctime>
#include <stdio.h>
#include <string>

#include "Block.h"
#include "Blockchain.h"

#include <vector>

// Blockchain
class Blockchain {
private:
  // Initial block
  Block createGenesisBlock();

public:
  // The blockchain is, as the name suggests, a list of blocks
  vector<Block> chain;

  // Constructor
  Blockchain();

  // Public methods
  void addBlock(TransactionData data);
  bool isChainValid();

  // Contrived Example for Demo Only
  Block *generateLatestBlock();
};

// Constructor
Blockchain::Blockchain() {
  // Genesis block
  Block genesis = createGenesisBlock();
  // push the genesis block to the chain
  chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock() {
  // it doesn't need anything special
  time_t current;
  TransactionData data;
  data.ammount = 0;
  data.recieverKey = "";
  data.senderKey = "";
  data.timestamp = time(&current);

  hash<int> hash1;
  Block genesis(0, data, hash1(0));
  return genesis;
}

// Only for Demo
Block *Blockchain::generateLatestBlock() { return &chain.back(); }

void Blockchain::addBlock(TransactionData data) {
  // Size minus 1 of chain is the latest index
  int index = (int)chain.size() - 1;
  // Get the hash of the latest block in order to add a new one
  Block newBlock(index, data, generateLatestBlock()->getHash());
}

bool Blockchain::isChainValid() {
  vector<Block>::iterator it;
  int chainLen = (int)chain.size();
  for (it = chain.begin(); it != chain.end(); ++it) {
    Block currentBlock = *it;
    if (!currentBlock.isHashValid()) {
      return false;
    }

    if (chainLen > 0) {
      Block prevBlock = *(it - 1);
      if (currentBlock.getPreviousHash()) {
        // INVALID
        return false;
      }
    }
  }
}
