#include <iostream>
#include "DB.h"

using namespace std;

DB db;

void GetAction(string key){
    int res = db.get(key);

    cout << "Attempting to get value for key " << key;
    cout << " in database...\n";

    if(res == NULL){
        cout << "\tThe key " << key << " doesn't exist in the database at the moment\n";
    }
    else{
        cout << "\t The value for key " << key << " is " << res << "\n";
    }
}

void PutAction(string key, int val){
    int res = db.get(key);

    cout << "Attempting to put value " << val << " for key " << key;
    cout << " in database...\n";

    try{
        db.put("A", 6);
        cout << "\tSuccessfully entered!\n";
    }
    catch(const exception& e){
        cerr << "\t" << e.what() << "\n";
    }
}

void BeginTransactionAction(){
    cout << "Attempting to begin transaction in database...\n";

    try{
        db.begin_transaction();
        cout << "\tSuccessfully began transaction!\n";
    }
    catch(const exception& e){
        cerr << "\t" << e.what() << "\n";
    }
}

void CommitTransactionAction(){
    cout << "Attempting to commit transaction in database...\n";

    try{
        db.commit();
        cout << "\tSuccessfully committed transaction!\n";
    }
    catch(const exception& e){
        cerr << "\t" << e.what() << "\n";
    }
}

void RollbackTransactionAction(){
    cout << "Attempting to rollback transaction in database...\n";

    try{
        db.rollback();
        cout << "\tSuccessfully rollbacked transaction!\n";
    }
    catch(const exception& e){
        cerr << "\t" << e.what() << "\n";
    }
}

void ResetAction(){
    cout << "Attempting to reset database...\n";

    try{
        db.reset();
        cout << "\tSuccessfully reset database!\n";
    }
    catch(const exception& e){
        cerr << "\t" << e.what() << "\n";
    }
}


void SampleRun(){

    ResetAction();
    cout << "\n";

    cout << "Shouldn't return anything since A doesn't exist in DB yet\n";
    GetAction("A");
    cout << "\n";

    cout << "Should not run because transaction isn't in progress\n";
    PutAction("A", 5);
    cout << "\n";

    cout << "Should start a transaction\n";
    BeginTransactionAction();
    cout << "\n";

    cout << "Should set A to 5\n";
    PutAction("A", 5);
    cout << "\n";

    cout << "Shouldn't return anything since A doesn't exist in DB yet due to no commit to DB\n";
    GetAction("A");
    cout << "\n";

    cout << "Should update A to 6\n";
    PutAction("A", 6);
    cout << "\n";

    cout << "Should commit transaction to DB\n";
    CommitTransactionAction();
    cout << "\n";

    cout << "Should succesully return A's value as 6\n";
    GetAction("A");
    cout << "\n";

    cout << "Shouldn't commit since there is no transaction in progress\n";
    CommitTransactionAction();
    cout << "\n";

    cout << "Shouldn't rollback since there is no transaction in progress\n";
    RollbackTransactionAction();
    cout << "\n";

    cout << "Shouldn't return anything since B doesn't exist in DB yet\n";
    GetAction("B");
    cout << "\n";

    cout << "Should start a transaction\n";
    BeginTransactionAction();
    cout << "\n";

    cout << "Should set B to 10\n";
    PutAction("B", 10);
    cout << "\n";

    cout << "Should rollback\n";
    RollbackTransactionAction();
    cout << "\n";

    cout << "Shouldn't return anything since B doesn't exist in DB yet\n";
    GetAction("B");
    cout << "\n";

}


void ShowPrompt(){
        cout << "Select the following options: \n";
        cout << "1. Begin Transaction [begin_transaction()]\n";
        cout << "2. Enter data [put(key, value)]\n";
        cout << "3. Get Data [get(key)]\n";
        cout << "4. Commit Transaction [commit()]\n";
        cout << "5. Rollback Transaction [rollback()]\n";
        cout << "6. Reset Database (Start all over again)\n";
        cout << "7. Sample Run (Based on figures from assignment document)\n";
        cout << "8. Exit Program\n";

        cout << "Enter a single number option: ";
}

int main(){

    int option;
    string key;

    do{
        ShowPrompt();
        cin >> option;
        cout << "\n";

        switch(option){
            case 1:
                BeginTransactionAction();
                break;
            case 2:
                cout << "Enter the string input for the key: ";
                cin >> key;

                //cout << "\n";

                cout << "Enter the integer input for the value: ";
                int val;
                cin >> val;
                cout << "\n";

                PutAction(key, val);
                break;
            case 3:
                cout << "Enter the string input for the key: ";
                cin >> key;

                cout << "\n";

                GetAction(key);
                break;
            case 4:
                CommitTransactionAction();
                break;
            case 5:
                RollbackTransactionAction();
                break;
            case 6:
                ResetAction();
                break;
            case 7:
                SampleRun();
                ResetAction();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "You entered an invalid option, please try again.";
                break;
        }

        cout << "\n-----------------------------------------------\n";
    }
    while(option != 8);

    //DB db;
    //SampleRun();



    return 0;
}