// ------------------------------------ comedy.cpp ------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for the comedy movie subclass, storing all neccessary movie data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "comedy.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//------------------------------------ constructor ------------------------------------
// Default constructor, will take in string and parse title, release_year, director, 
// quantity
// Preconditions: None
// Postconditions: A new fully initialized comedy movie object 
Comedy::Comedy(string input) {
    stringstream input_stream(input);
    string token;
    string data_piece;
    int i = 0;
    while (input_stream >> token) {
        if (token.back() == ',') {
            token.pop_back();
            i++;
        }
        else token.append(" ");
        if (i > 1) {
            data_piece.append(token);
        }
        if (i == 2 && quantity == 0) {
            quantity += stoi(data_piece);
            data_piece = "";
        }
        if (i == 3 && director.length() == 0) {
            director = data_piece;
            data_piece = "";
        }
        if (i == 4 && title.length() == 0) {
            title = data_piece;
            data_piece = "";
        }
        if (i == 5 && release_year == 0) {
            release_year = stoi(data_piece);
            data_piece = "";
        }
        if (i == 4) i++;
    }
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//----------------------------------- setQuantity -------------------------------------
// Sets the quantity of this movie to the input int
// Preconditions: A movie object
// Postconditions: A new quantity value
void Comedy::setQuantity(int new_quantity) {
    quantity = new_quantity;
}

/*
*------------------------------------ ACCESSORS ---------------------------------------
*/
//------------------------------------ getData ----------------------------------------
// Return all movie data as string
// Preconditions: A movie object
// Postconditions: A string of all movie data
string Comedy::getData() const {
    return to_string(quantity) + ", " + director + ", " + title + ", " + to_string(release_year);
}

//--------------------------------- getSortingData ------------------------------------
// Get data relevant for sorting
// Preconditions: A movie object
// Postconditions: Returns a tuple of two pieces sorting data
tuple<string, string> Comedy::getSortingData() const {
    tuple<string, string> sorting_data;
    get<0>(sorting_data) = title;
    get<1>(sorting_data) = to_string(release_year);
    return sorting_data;
}

//---------------------------------- getQuantity --------------------------------------
// Retrieves quantity of this movie in inventory
// Preconditions: A movie object 
// Postconditions: Returns the quantity of this movie in inventory
int Comedy::getQuantity() const {
    return quantity;
}

//----------------------------------- getTitle ----------------------------------------
// Retrieves the title of this movie
// Preconditions: A movie object
// Postconditions: Returns the title of this movie
string Comedy::getTitle() const {
    return title;
}
