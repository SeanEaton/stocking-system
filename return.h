// ------------------------------------ return.h --------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for the return action type, performs the action itself while storing all
// neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
class Store;
#include "store.h"
class Customer;
#include "action.h"
#include "customer.h"
#include "movie.h"

class Return : public Action {
    public:
        Return(string, Store*, bool&); //default constructor, takes in a string to parse action data, as
                                       //well as a pointer to the store upon which it is executing, and a 
                                       //reference boolean to indicate whether execution was successful
        bool execute(); //performs the actual "returning" on this Action's Store variable's 
                        //inventory, increasing the returned Movie object's quantity variable by 
                        //one
        string getActionData() const; //print this action's data -> movie data followed by borrowed or returned;

    private:
        Movie* findMovie(Store*, char); //searches a given store for a movie of the given type 
                                        //based off given search data tuple
        tuple<string, string> searching_data; //the two pieces of data used to search for their desired movie
        Customer* cstmr; //the Customer who performed this Action
        Movie* mv; //the Movie upon which this Action was performed
};
#endif