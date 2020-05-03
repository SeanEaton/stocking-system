// ------------------------------------- store.h --------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for primary store business logic and data structures
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef STORE_H
#define STORE_H
class Customer;
#include "customer.h"
class Movie;
#include "movie.h"
#include "moviefactory.h"
#include "action.h"
#include "actionfactory.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <tuple>

using namespace std;

const int CUSTOMER_CAPACITY = 223; //amount of bucket spots in the customer hashtable

class Store {
    public:
        Store(); //basic constructor, will instantiate inventory and customer data structures
        ~Store(); //deconstructor, will clear movie inventories and customer hashtable
        bool buildInventory(ifstream&); //takes in an input file of text designating movies and movie 
                                        //data, calls createMovie() in moviefactory, which will 
                                        //construct each movie object
        bool buildCustomers(ifstream&); //takes in an input file of text designating customer IDs and 
                                        //names, constructs and hashes each customer using this data
        Customer* createCustomer(string); //constructs and returns a new customer based of input sent via buildCustomers
        bool storeCustomer(Customer*); //recieves a customer pointer and stores it in the customer hashtable
        Customer* findCustomer(int); //searches the customer hashtable for a matching id
        bool doActions(ifstream&);  //takes in an input file of text designating action types, and 
                                    //data relevant to those action types, calls createAction() in 
                                    //actionfactory, which will construct each action object then 
                                    //will call the execute function of each action
        list<Movie*>& getComedyInv(); //retrieve a reference for this store's inventory of movies - comedy, drama, classic separately
        list<Movie*>& getDramaInv();
        list<Movie*>& getClassicInv();
        void displayInventories(); //print the inventories to terminal  
        void displayCustomers(); //print the customers to terminal   

    private:
        list<Movie*> comedy_inventory; //a collection of pointers to Movie objects, representing
                                       //this Store's inventory
        list<Movie*> drama_inventory;
        list<Movie*> classic_inventory;
        Customer* customers[CUSTOMER_CAPACITY]; //a collection of Customer objects in a hashtable
        int hashCustomer(Customer*, int); //linear probing hash collision resolution
};
#endif