#include "DB.h"
#include <stdexcept>

using namespace std;

// Will return the value associated with the key 
// or null if the key doesn’t exist
// can be called anytime even when a transaction is not in progress
int DB::get(string key){
    if(mainData.count(key) == 0) return NULL;

    return mainData[key];
}

// Will create a new key with the provided value if a key doesn’t exist. 
// Otherwise it will update the value of an existing key.
// If called when a transaction is not in progress, throw an exception
void DB::put(std::string key, int val){
    if(!inTransaction) throw runtime_error("No transaction in progress");
    
    transactionData[key] = val;
}

// Starts a new transaction
// At a time only a single transaction may exist
void DB::begin_transaction(){
    if(inTransaction) throw runtime_error("Transaction already in progress");
    
    inTransaction = true;
    transactionData.clear();
}

// applies changes made within the transaction to the main state. 
// Allowing any future gets() to “see” the changes made within the transaction
void DB::commit(){
    if(!inTransaction) throw runtime_error("No transaction in progress");

    mainData.insert(transactionData.begin(), transactionData.end());

    inTransaction = false;
    transactionData.clear();
}

// abort all the changes made within the transaction 
// and everything should go back to the way it was before
void DB::rollback(){
    if(!inTransaction) throw runtime_error("No transaction in progress");
    
    inTransaction = false;
    transactionData.clear();
}

// Only for testing purposes
void DB::reset(){
    inTransaction = false;
    transactionData.clear();
    mainData.clear();
}