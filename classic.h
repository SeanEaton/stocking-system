// ----------------------------------- classic.h --------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration for the classic movie subclass, storing all neccessary movie data
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"


using namespace std;

class Classic : public Movie {
    public:
        Classic(string input); //default constructor, will take in string and parse title, release_year, director, 
                               //quantity, actor and release_date
        string getData() const; //get all data as string
        tuple<string, string> getSortingData() const; //get data relevant to sorting (release date(year, day), actor)
        int getQuantity() const; //retrieves quantity of this movie in inventory
        void setQuantity(int); //sets the quantity of this movie to the input int
        string getTitle() const; //retrieves the title of this movie

    private:
        string actor; //an actor in this Classic
        int release_day = 0; //the release day of this Classic
};
#endif