#include <stdio.h>
#include <string>

#include "Block.h"

// Block Class
class Block {
private:
  int index;
  size_t blockHash;
  size_t previousHash;
  size_t generateHash();

public:
  // Constructor
  /**
   * @brief Construct a new Block object
   *
   * @param index position of block
   * @param d Transaction object
   * @param previousHash hash of previous block
   */
  Block(int index, TransactionData d, size_t previousHash);

  // Get Original Block
  size_t getHash();

  // Get previousHash
  size_t getPreviousHash();

  // TransactionData
  TransactionData data;

  // Validate Hash
  bool isHashvalid();
};

// Constructor with Parameters
Block::Block(int index, TransactionData d, size_t previousHash) {
  index = index;
  data = d;
  previousHash = previousHash;
  blockHash = generateHash();
};

// Private functions
size_t Block::generateHash() {
  hash<string> hash1;
  hash<size_t> hash2;
  hash<size_t> finalHash;
  // concatenate the hash values
  string toHash = to_string(data.ammount) + data.recieverKey + data.senderKey +
                  to_string(data.timestamp);

  return finalHash(hash1(toHash) + hash2(previousHash));
};

// Public functions

// Get Block Hash member
size_t Block::getHash() { return blockHash; }
// Get previous block hash
size_t Block::getPreviousHash() { return previousHash; }
// Check validity of hash
bool Block::isHashvalid() { return generateHash() == blockHash; }
