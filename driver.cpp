// -------------------------------- driver.cpp ----------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Driver file for a store program, used for reading in data for storage and testing 
// class
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "store.h"

int main() {
    Store my_store;
    ifstream infile("data4movies.txt");
    my_store.buildInventory(infile); //stock movie inventories

    ifstream infile2("data4customers.txt");
    my_store.buildCustomers(infile2); //populate customer hashtable

    ifstream infile3("data4commands.txt");
    my_store.doActions(infile3); //create actions and execute them

    return 0;
}