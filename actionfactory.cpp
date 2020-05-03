// -------------------------------- actionfactory.cpp ---------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation of moviefactory methods, used for creating, storing, and executing 
// action objects
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "actionfactory.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//----------------------------------- constructor -------------------------------------
// Default constructor, initialized the store for which this factory will be making
// actions
// Preconditions: None
// Postconditions: A actionfactory object with client store
ActionFactory::ActionFactory(Store* client_store) {
    owner = client_store;
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//-------------------------------------------------------------------------------------
// Constructs and calls execution on an Action object based off inputs given via the 
// doAction function of a Store object.
// Preconditions: An actionfactory object
// Postconditions: A new action object will be created and executed, and deleted unless
// it will be stored in a customer's history list
bool ActionFactory::initiateAction(string input) {
    char action_type;
    action_type = input[0];
    bool valid = true;
    switch (action_type) {
        case 'B' : {
            Action* new_action = new Borrow(input, owner, valid);
            if (valid == false) {
                delete new_action;
            }
            else new_action->execute();
            return true;
        }
        case 'R' : {
            Action* new_action = new Return(input, owner, valid);
            if (valid == false) {
                delete new_action;
            }
            else new_action->execute();
            return true;
        }
        case 'I' : {
            Action* new_action = new Inquiry(input, owner, valid);
            if (valid == false) {
                delete new_action;
            }
            else new_action->execute();
            delete new_action;
            return true;
        }
        case 'H' : {
            Action* new_action = new History(input, owner, valid);
            if (valid == false) {
                delete new_action;
            }
            else new_action->execute();
            delete new_action;
            return true;
        }
        default : {
            cout << "Invalid action type: \"" << action_type << "\" -> from command string: \"" << input << "\"" << endl;
            return false;
        }
    }
    return false;
}