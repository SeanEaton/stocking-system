// ----------------------------------- customer.h -------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for customer object data structures and methods, representing a customer
// and their transaction history
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "action.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Customer {
    public:
        Customer(string, string, int); //default constructor, will have parameter to set first and last name, and id
        ~Customer(); //destructor, clears history list
        void getHistory(); //will output a complete history of actions associated with this Customer 
                           //in chronological order
        void makeHistory(Action*); //stores a new action object in customer's history list
        void displayCustomer() const; //prints the customer data
        int getID() const; //returns the customer id
    private:
        list<Action*> history; //a collection of this Customer's actions, 
        string first_name; //first name of this Customer
        string last_name; //last name of this Customer
        int id; //ID number of this Customer
};
#endif