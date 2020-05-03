// ---------------------------------- customer.cpp ------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for customer object data structures and methods, representing a 
// customer and their transaction history
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "customer.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//----------------------------------- constructor -------------------------------------
// Default contructor, initializing customer ID, first, and last name
// Preconditions: None
// Postconditions: A customer object with initialized ID, first, and last name
Customer::Customer(string first, string last, int customer_id) {
    first_name = first;
    last_name = last;
    id = customer_id;
}

//----------------------------------- destructor --------------------------------------
// Destroys history list
// Preconditions: A customer object 
// Postconditions: The object's data structures are cleared from memory
Customer::~Customer() {
    list<Action*>::iterator it;
    for (it = history.begin(); it != history.end(); ++it) {
        delete *it;
    }
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//----------------------------------- makeHistory -------------------------------------
// Stores a new action object in customer's history list
// Preconditions: A customer object
// Postconditions: A new action object in customer's history list
void Customer::makeHistory(Action* new_action) {
    history.push_front(new_action);
}

/*
*------------------------------------ ACCESSORS ---------------------------------------
*/
//-------------------------------- displayCustomer ------------------------------------
// Prints the customer data by ID, first name, then last name
// Preconditions: A customer object
// Postconditions: Customer data outputted
void Customer::displayCustomer() const {
    cout << id << " " << first_name << " " << last_name;
}

//------------------------------------ getID ------------------------------------------
// Returns the customer id
// Preconditions: A customer object
// Postconditions: Customer ID returned
int Customer::getID() const {
    return id;
}

//---------------------------------- getHistory ---------------------------------------
// Will output a complete history of actions associated with this Customer in 
// chronological order
// Preconditions: A customer object
// Postconditions: Customer action history list will be outputted 
void Customer::getHistory() {
    list<Action*>:: iterator it;
    for (it = history.begin(); it != history.end(); it++) {
        cout << (*it)->getActionData() << endl;
    }
}