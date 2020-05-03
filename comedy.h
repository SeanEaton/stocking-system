// ----------------------------------- comedy.h ---------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for the comedy movie subclass, storing all neccessary movie data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"
#include <string>

class Comedy : public Movie {
    public:
        Comedy(string); //default constructor, will take in string and parse title, release_year, 
                        //director, quantity
        string getData() const; //get all data as string
        tuple<string, string> getSortingData() const; //get data relevant for sorting (title, release year)
        int getQuantity() const; //retrieves quantity of this movie in inventory
        void setQuantity(int); //sets the quantity of this movie to the input int
        string getTitle() const; //retrieves the title of this movie

};
#endif