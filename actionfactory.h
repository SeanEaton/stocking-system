// -------------------------------- actionfactory.h -----------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration of moviefactory methods, used for creating, storing, and executing 
// action objects
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H
class Store;
#include "store.h"
class Action;
#include "action.h"
#include "borrow.h"
#include "return.h"
#include "inquiry.h"
#include "history.h"
#include <iostream>
#include <string>
#include <list>

class ActionFactory {
    public: 
        ActionFactory(Store*); //default constuctor
        bool initiateAction(string); //constructs and calls execution on a Action object based off inputs 
                                     //given via the doAction function of a Store object.
    private:
        Store* owner; //the store for which this action factory is creating action, so that we can move into 
                      //it's storage
};
#endif