// ----------------------------------- action.h ---------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for abstract action class, with virtual function to be implemented by
// action subclasses
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef ACTION_H
#define ACTION_H
#include <string>

using namespace std;

class Action {
    public: 
        virtual bool execute() = 0; //this function will be defined within each subclass, as each action 
                                    //will perform different operations on a Store's inventory or a customer's 
                                    //history
        virtual string getActionData() const = 0; //print this action's data
};
#endif