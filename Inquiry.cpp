// ---------------------------------- inquiry.cpp -------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for the inquiry action type, performs the action itself while storing 
// all neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "inquiry.h"

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
Inquiry::Inquiry(string input, Store* target_store, bool& valid) {
    valid = true;
    str = target_store;
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//------------------------------------ execute ----------------------------------------
// Performs the actual "inquiring" on this Action's Store variable's inventory, 
// outputing all Comedy movies, then all Dramas, then all Classics. 
// Preconditions: An action object
// Postconditions: All Comedy movies, then all Dramas, then all Classics are outputted
bool Inquiry::execute() {
    cout << "Store inventory: " << endl;
    str->displayInventories();
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
string Inquiry::getActionData() const {
    return "";
}