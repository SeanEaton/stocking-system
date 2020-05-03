// -------------------------------- moviefactory.h ------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Declaration of moviefactory methods, used for creating and storing movie objects
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H
class Store;
#include "store.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class MovieFactory {
    public:
        MovieFactory(Store*); //default constructor
        bool createMovie(string); //constructs a Movie object based off inputs given via the buildInventory
                            //function of a Store object. Will recieve a set of inputs outlining the type
                            //of Movie to be created (Drama, Comedy, Classic), and the proper inputs
                            //for the constructor of that Movie subclass object.
        bool stockComedy(Movie*, list<Movie*>&); //stocks movie in sorted manner
        bool stockDrama(Movie*, list<Movie*>&); 
        bool stockClassic(Movie*, list<Movie*>&);

    private:
        Store* owner; //the store for which this movie factory is creating movies, so that we can move into 
                      //it's storage
};
#endif