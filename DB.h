#pragma once

#include <string>
#include <unordered_map>

#ifndef DB_H
#define DB_H

class DB{
private:
    std::unordered_map<std::string, int> mainData, transactionData;
    bool inTransaction = false;

public:

    DB() {}
    
    // Will return the value associated with the key 
    // or null if the key doesn’t exist
    // can be called anytime even when a transaction is not in progress
    int get(std::string key);

    // Will create a new key with the provided value if a key doesn’t exist. 
    // Otherwise it will update the value of an existing key.
    // If called when a transaction is not in progress, throw an exception
    void put(std::string key, int val);
    
    // Starts a new transaction
    // At a time only a single transaction may exist
    void begin_transaction();

    // applies changes made within the transaction to the main state. 
    // Allowing any future gets() to “see” the changes made within the transaction
    void commit();

    // abort all the changes made within the transaction 
    // and everything should go back to the way it was before
    void rollback();

    // Only for testing purposes
    void reset();
};

#endif