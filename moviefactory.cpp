// -------------------------------- moviefactory.cpp ----------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation of moviefactory methods, used for creating and storing movie objects
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "moviefactory.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//----------------------------------- constructor -------------------------------------
// Default constructor, initialized the store for which this factory will be making
// movies
// Preconditions: None
// Postconditions: A moviefactory object with client store
MovieFactory::MovieFactory(Store* client_store) {
    owner = client_store;
}

/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//----------------------------------- createMovie -------------------------------------
// Constructs a Movie object based off inputs given via the buildInventory function of 
// a Store object. Will recieve a set of inputs outlining the type of Movie to be 
// created (Drama, Comedy, Classic), and the proper inputs for the constructor of that 
// Movie subclass object.
// Preconditions: A moviefactory object and movie construction string
// Postconditions: Movies will be stores in client store's movie sets
bool MovieFactory::createMovie(string input) {
    char movie_type;
    movie_type = input[0];
    switch (movie_type) {
        case 'F' : {
            Movie* new_movie = new Comedy(input);
            stockComedy(new_movie, owner->getComedyInv());
            return true;
        }
        case 'D' : {
            Movie* new_movie = new Drama(input);
            stockDrama(new_movie, owner->getDramaInv());
            return true;
        }
        case 'C' : {
            Movie* new_movie = new Classic(input);
            stockClassic(new_movie, owner->getClassicInv());
            return true;
        }
        default : {
            cout << "Invalid movie type: \"" << movie_type << "\" -> from command string: \"" << input << "\"" << endl;
            return false;
        }
    }
    return false;
}

//-------------------------------- stockComedy ----------------------------------------
// Stores comedy movie object into this movie factory's comedy inventory based on 
// comedy movie's sorting criteria
// Preconditions: A moviefactory object and a movie object, and a store inventory
// Postconditions: The movie object will be stored, or if it already exists, the 
// quantity will be increased
bool MovieFactory::stockComedy(Movie* mv, list<Movie*>& inventory) {
    if (inventory.size() == 0) inventory.push_back(mv);
    else {
        bool stocked = false;
        list<Movie*>::iterator it;
        tuple<string, string> sorting_data = mv->getSortingData();
        for (it = inventory.begin(); it != inventory.end(); it++) {
            if (get<0>((*it)->getSortingData()) > get<0>(sorting_data)) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>((*it)->getSortingData()) == get<0>(sorting_data)) && (stoi(get<1>((*it)->getSortingData())) > stoi(get<1>(sorting_data)))) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>((*it)->getSortingData()) == get<0>(sorting_data)) && (stoi(get<1>((*it)->getSortingData())) == stoi(get<1>(sorting_data)))) {
                (*it)->setQuantity((*it)->getQuantity() + mv->getQuantity());
                stocked = true;
                break;
            }
        }
        if (stocked == false) inventory.push_back(mv);
    }
    return true;
}

//-------------------------------- stockDrama -----------------------------------------
// Stores drama movie object into this movie factory's drama inventory based on drama 
// movie's sorting criteria
// Preconditions: A moviefactory object and a movie object, and a store inventory
// Postconditions: The movie object will be stored, or if it already exists, the 
// quantity will be increased 
bool MovieFactory::stockDrama(Movie* mv, list<Movie*>& inventory) {
    if (inventory.size() == 0) inventory.push_back(mv);    
    else {
        bool stocked = false;
        list<Movie*>::iterator it;
        tuple<string, string> sorting_data = mv->getSortingData();
        for (it = inventory.begin(); it != inventory.end(); it++) {
            if (get<0>((*it)->getSortingData()) > get<0>(sorting_data)) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>((*it)->getSortingData()) == get<0>(sorting_data)) && (get<1>((*it)->getSortingData()) > get<1>(sorting_data))) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>((*it)->getSortingData()) == get<0>(sorting_data)) && (get<1>((*it)->getSortingData()) == get<1>(sorting_data))) {
                (*it)->setQuantity((*it)->getQuantity() + mv->getQuantity());
                stocked = true;
                break;
            }
        }
        if (stocked == false) inventory.push_back(mv);
    }
    return true;
}

//-------------------------------- stockClassic ---------------------------------------
// Stores classic movie object into this movie factory's classic inventory based on 
// classic movie's sorting criteria
// Preconditions: A moviefactory object and a movie object, and a store inventory
// Postconditions: The movie object will be stored, or if it already exists, the 
// quantity will be increased
bool MovieFactory::stockClassic(Movie* mv, list<Movie*>& inventory) {
    if (inventory.size() == 0) inventory.push_back(mv);
    else {
        bool stocked = false;
        list<Movie*>::iterator it;
        tuple<string, string> sorting_data = mv->getSortingData();
        tuple<int, int> release_date;
        stringstream input_stream(get<0>(sorting_data));
        string token;
        int i = 0;
        while (input_stream >> token) {
            if (i == 0) get<0>(release_date) = stoi(token);
            else get<1>(release_date) = stoi(token);
            i++;
        }
        for (it = inventory.begin(); it != inventory.end(); it++) {
            tuple<int, int> release_date2;
            stringstream input_stream2(get<0>((*it)->getSortingData()));
            string token2;
            int j = 0;
            while (input_stream2 >> token) {
                if (j == 0) get<0>(release_date2) = stoi(token);
                else get<1>(release_date2) = stoi(token);
                j++;
            }
            if (get<0>(release_date2) > get<0>(release_date)) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>(release_date2) == get<0>(release_date)) && (get<1>(release_date2) > get<1>(release_date))) {
                inventory.insert(it, mv);
                stocked = true;
                break;
            }
            else if ((get<0>(release_date2) == get<0>(release_date)) && (get<1>(release_date2) == get<1>(release_date))) {
                (*it)->setQuantity((*it)->getQuantity() + mv->getQuantity());
                stocked = true;
                break;
            }
        }
        if (stocked == false) inventory.push_back(mv);
    }
    return true;
}

