// ----------------------------------- borrow.cpp -------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for the borrow action type, performs the action itself while storing 
// all neccesary data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "borrow.h"

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
Borrow::Borrow(string input, Store* target_store, bool& valid) {
    stringstream input_stream(input);
    string token;
    string data_piece;
    char media_type;
    char movie_type;
    int i = 0;
    while (input_stream >> token) { //parse string into instructional data members
        if (i == 1) {
            cstmr = target_store->findCustomer(stoi(token));
            if (cstmr == NULL) {
                valid = false;
                cout << "Invalid customer ID: \"" << stoi(token) << "\" -> from command string: \"" << input << "\"" << endl;
                break;
            }
        } 
        if (i == 2) {
            media_type = token[0];
            switch (media_type) {
                case 'D' : break;
                default : {
                    valid = false;
                    cout << "Invalid media type: \"" << token[0] << "\" -> from command string: \"" << input << "\"" << endl;
                    break;
                }
            }
            if (valid == false) break;
        }
        if (i == 3) {  
            movie_type = token[0];
            switch (movie_type) {
                case 'F' : break;   
                case 'D' : break;
                case 'C' : break;   
                default : {
                    valid = false;
                    cout << "Invalid movie type: \"" << movie_type << "\" -> from command string: \"" << input << "\"" << endl;
                    break;
                }
            }   
            if (valid == false) break;
        }
        if (i > 3) {
            if (movie_type == 'F') {
                data_piece.append(token);
                if (token.back() == ',') {
                    data_piece.pop_back();
                    get<0>(searching_data) = data_piece;
                    data_piece = "";
                    i++;
                }
                else if (i < 5) data_piece.push_back(' ');
                if (i == 5) get<1>(searching_data) = data_piece;
            }
            if (movie_type == 'D') {
                data_piece.append(token);
                if (token.back() == ',') {
                    data_piece.pop_back();
                    if (i == 5) get<1>(searching_data) = data_piece;
                    if (i == 4) {
                        get<0>(searching_data) = data_piece;
                        i++;
                    }
                    data_piece = "";
                }
                else data_piece.push_back(' ');
            }            
            if (movie_type == 'C') {
                if (i > 5) {
                    data_piece.append(token);
                    data_piece.push_back(' ');
                }
                if (i == 5) {
                    data_piece = token + " " + data_piece;
                    get<0>(searching_data) = data_piece;
                    data_piece = "";
                    i++;
                }
                if (i == 4) {
                    data_piece = token;
                    i++;
                }
            }
        }
        if (i <= 3) i++;
    }
    if (movie_type == 'C') {
        data_piece.pop_back();
        get<1>(searching_data) = data_piece;
    }
    if (valid == true) {
        mv = findMovie(target_store, movie_type);
        if (mv == NULL) {
            valid = false;
            cout << "Invalid search criteria: \"" << get<0>(searching_data) << "\" or \"" << get<1>(searching_data) << "\" -> from command string: \"" << input << "\"" << endl;
        }
    }
    if (valid == true) cstmr->makeHistory(this);
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//------------------------------------ execute ----------------------------------------
// Performs the actual "borrowing" on this Action's Store variable's inventory, 
// reducing the borrowed Movie object's quantity variable by one
// Preconditions: An action object
// Postconditions: Borrowed Movie object's quantity variable reduced by one unless 
// quantity is already at 0 
bool Borrow::execute() {
    if (mv->getQuantity() > 0) mv->setQuantity(mv->getQuantity() - 1);
    else {
        cout << "BORROW FAILED: " << mv->getTitle() << " OUT OF STOCK -> borrow requested by ";
        cstmr->displayCustomer();
        cout << endl;
        success = false;
    }
    return true;
}

//----------------------------------- findMovie ---------------------------------------
// Searches a given store for a movie of the given type based off given search data 
// tuple
// Preconditions: An action object w/ searching_data and a target store and movie_type
// Postconditions: Returns the movie which was being searched for, or else NULL
Movie* Borrow::findMovie(Store* target_store, char movie_type) {
    list<Movie*>::iterator it;
    switch (movie_type) {
        case 'F' : {
            for (it = target_store->getComedyInv().begin(); it != target_store->getComedyInv().end(); it++) {
                if (get<0>((*it)->getSortingData()) == get<0>(searching_data) && get<1>((*it)->getSortingData()) == get<1>(searching_data)) {
                    return (*it);
                }
            }
        }
        case 'D' : {
            for (it = target_store->getDramaInv().begin(); it != target_store->getDramaInv().end(); it++) {
                if (get<0>((*it)->getSortingData()) == get<0>(searching_data) && get<1>((*it)->getSortingData()) == get<1>(searching_data)) {
                    return (*it);
                }
            }
        }
        case 'C' : {
            for (it = target_store->getClassicInv().begin(); it != target_store->getClassicInv().end(); it++) {
                if (get<0>((*it)->getSortingData()) == get<0>(searching_data)) {
                    return (*it);
                }
            }
        }
    }
    return NULL;
}

/*
*------------------------------------ ACCESSORS ---------------------------------------
*/
//---------------------------------- getActionData ------------------------------------
// Prints this action's data -> movie data followed by RETURNED;
// Preconditions: An action object, will be a successful action
// Postconditions: Action's data is outputted
string Borrow::getActionData() const {
    if (mv != NULL) {
        if (success) return mv->getTitle() + ": BORROWED";
        else return mv->getTitle() + ": FAILED BORROW (OUT OF STOCK)";
    }
    return "action failed, and shouldn't be in this history list";
}