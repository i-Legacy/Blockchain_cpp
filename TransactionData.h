//
//  TransactionData.h
//  BlockChainExample
//
//  Created by Jon on 1/10/18.
//  Copyright © 2018 Crypto Enthusiasts. All rights reserved.
//

#ifndef TransactionData_h
#define TransactionData_h

#include <string>

using namespace std;

struct TransactionData {
  double ammount;
  string senderKey;
  string recieverKey;
  time_t timestamp;

  TransactionData(){};

  TransactionData(double amt, string sender, string receiver, time_t time) {
    ammount = amt;
    senderKey = sender;
    recieverKey = receiver;
    timestamp = time;
  };
};

#endif /* TransactionData_h */