// ---------------------------------- history.cpp -------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for the history action type, performs the action itself while storing 
// all neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "history.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//------------------------------------ constructor ------------------------------------
// Default constructor, takes in a string to parse action data, as well as a pointer to 
// the store upon which it is executing, and a reference boolean to indicate whether 
// execution was successful
// Preconditions: None
// Postconditions: A fully execution-ready action object, unless data is insufficient, 
// in which case action object is deleted immediately
History::History(string input, Store* target_store, bool& valid) {
    stringstream input_stream(input);
    string token;
    int i = 0;
    while (input_stream >> token) {
        if (i == 1) {
            cstmr = target_store->findCustomer(stoi(token));
            if (cstmr == NULL) {
                valid = false;
                cout << "Invalid customer ID: \"" << stoi(token) << "\" -> from command string: \"" << input << "\"" << endl;
                break;
            }
        } 
        i++;
    }
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//------------------------------------ execute ----------------------------------------
// Will output the history of a particular Customer's (cstmr) borrow and return 
// functions at this Action's Store variable
// Preconditions: An action object
// Postconditions: This action's customer's jistory list will be outputted
bool History::execute() {
    cstmr->displayCustomer();
    cout << "'s History: " << endl;
    cstmr->getHistory();
    cout << endl;
    return true;
}

/*
*------------------------------------ ACCESSORS ---------------------------------------
*/
//---------------------------------- getActionData ------------------------------------
// Prints this action's data -> will do nothing.
// Preconditions: An action object
// Postconditions: Empty string
string History::getActionData() const {
    return "";
}