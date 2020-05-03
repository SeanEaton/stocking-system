// -------------------------------- history.h -----------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for the history action type, performs the action itself while storing 
// all neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
class Store;
#include "store.h"
class Customer;
#include "action.h"
#include "customer.h"

class History : public Action {
    public:
        History(string, Store*, bool&); //default constructor, takes in a string to parse action data, as
                                        //well as a pointer to the store upon which it is executing, and a 
                                        //reference boolean to indicate whether execution was successful
        bool execute(); //will output the history of a particular Customer's (cstmr) borrow and return 
                        //functions at this Action's Store variable
        string getActionData() const; //print this action's data -> nothing in this case

    private:
        Customer* cstmr; //the Customer who will have their history printed
};
#endif