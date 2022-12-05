#include "iostream"

#include "Block.h"
#include "Blockchain.h"
#include "TransactionData.h"

using namespace std;

int main() {

  // Instance Blockchain
  Blockchain IvoCoin;

  // First Block
  TransactionData firstTransaction;
  time_t firstTransactionTime;
  firstTransaction.ammount = 2;

  cout << "Is chain valid?" << endl << IvoCoin.isChainValid() << endl;
}