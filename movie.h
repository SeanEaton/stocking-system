// ----------------------------------- movie.h ----------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for abstract movie class, with virtual function to be implemented by
// movie subclasses
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
using namespace std;

class Movie {
    public:
        virtual string getData() const = 0; //return a string which contains all data members in sequence
        virtual tuple<string, string> getSortingData() const = 0; //return a tuple of sorting attributes as strings
        virtual int getQuantity() const = 0; //return the quantity of this item in inventory
        virtual void setQuantity(int) = 0; //set the quanitity of this item to the input parameter
        virtual string getTitle() const = 0;

    protected:
        string title; //title of this Movie
        int release_year = 0; //release year of this Movie
        string director; //director of this Movie
        int quantity = 0; //quantity of this Movie
};
#endif