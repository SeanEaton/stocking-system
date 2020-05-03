// ---------------------------------- inquiry.h ---------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for the inquiry action type, performs the action itself while storing 
// all neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef INQUIRY_H
#define INQUIRY_H
class Store;
#include "store.h"
#include "action.h"

class Inquiry : public Action {
    public:
        Inquiry(string, Store*, bool&); //default constructor, takes in a string to parse action data, as
                                        //well as a pointer to the store upon which it is executing, and a 
                                        //reference boolean to indicate whether execution was successful
        bool execute(); //performs the actual "inquiring" on this Action's Store variable's 
                        //inventory, outputing all Comedy movies, then all Dramas, then all 
                        //Classics. 
        string getActionData() const; //print this action's data -> nothing in this case

    private:    
        Store* str; //the Store within which this Action was performed

};
#endif