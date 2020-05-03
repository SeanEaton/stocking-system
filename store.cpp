// --------------------------------- store.cpp ----------------------------------------
// Sean Eaton CSS502
// Created: March 13th, 2020
// Last Modified: March 15th, 2020
// ------------------------------------------------------------------------------------
// Implementation for primary store business logic and data structures
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------
#include "store.h"

/*
*------------------------------ CONSTRUCTORS/DESTRUCTORS ------------------------------
*/
//-------------------------------- constructor ----------------------------------------
// Default contructor, initializing all storage data structures (customers and movies)
// Preconditions: None.
// Postconditions: A store object with an initialized customer hashtable and movie sets
Store::Store() {
    for (int i = 0; i < CUSTOMER_CAPACITY; i++) {
        customers[i] = NULL;
    }
}

//--------------------------------- destructor ----------------------------------------
// Destroys movie sets and customer list
// Preconditions: A store object 
// Postconditions: The object's data structures are cleared from memory
Store::~Store() {
    list<Movie*>::iterator it;
    for (it = comedy_inventory.begin(); it != comedy_inventory.end(); ++it) {
        delete *it;
    }
    for (it = drama_inventory.begin(); it != drama_inventory.end(); ++it) {
        delete *it;
    }
    for (it = classic_inventory.begin(); it != classic_inventory.end(); ++it) {
        delete *it;
    }
    for (int i = 0; i < CUSTOMER_CAPACITY; ++i) {
        delete customers[i];
        customers[i] = NULL;
    }
}


/*
*------------------------------------- MUTATORS ---------------------------------------
*/
//--------------------------------- buildInventory ------------------------------------
// Takes in an input file of text designating movies and movie data, calls 
// createMovie() in moviefactory, which will construct each movie object
// Preconditions: A store object and valid input file
// Postconditions: A stocked movie inventory (if input file has any valid lines)
bool Store::buildInventory(ifstream& infile) {
    string line; 
    MovieFactory movie_maker = MovieFactory(this);
    while (getline(infile, line)) {
        movie_maker.createMovie(line);
    }
    return true;
}

//------------------------------- buildCustomers --------------------------------------
// Takes in an input file of text designating customer IDs and names, constructs and 
// hashes each customer using this data
// Preconditions: A store object and valid input file
// Postconditions: A filled customer hashtable (if input file has valid lines)
bool Store::buildCustomers(ifstream& infile) {
    string line;
    while (getline(infile, line)) {
        Customer* new_customer = createCustomer(line);
        int hash_index = hashCustomer(new_customer, 0);
        customers[hash_index] = new_customer;
    }
    return true;
}

//------------------------------- createCustomer --------------------------------------
// Constructs and returns a new customer based of input sent via buildCustomers
// Preconditions: none 
// Postconditions: A new customer object
Customer* Store::createCustomer(string input) {
    stringstream input_stream(input);
    string token;
    string first_name;
    string last_name;
    int id;
    int i = 0;
    while (input_stream >> token) {
        if (i == 0) id = stoi(token);
        if (i == 1) first_name = token;
        if (i == 2) last_name = token;
        i++;
    }
    Customer* new_customer = new Customer(first_name, last_name, id);
    return new_customer;
}

//--------------------------------- hashCustomer --------------------------------------
// Creates a hash index for a customer using their customer ID, and utilizes linear 
// probing hash collision resolution
// Preconditions: A valid customer object 
// Postconditions: A hash index for that customer
int Store::hashCustomer(Customer* cstmr, int collisions) {
    int hash_index = (cstmr->getID() % CUSTOMER_CAPACITY);
    int i = 0;
    while (customers[hash_index] != NULL) {
        i++;
        hash_index = ((cstmr->getID() % CUSTOMER_CAPACITY) + i) % CUSTOMER_CAPACITY;
    }
    return hash_index;
}

//--------------------------------- findCustomer --------------------------------------
// Looks for and returns a customer within the customer hashtable based off a ID value. 
// Will follow hash collision resolution formula until a customer is found with a match 
// ID value
// Preconditions: none
// Postconditions: A customer or NULL 
Customer* Store::findCustomer(int search_id) {
    int search_hash_index = (search_id % CUSTOMER_CAPACITY);
    int i = 0;
    while (customers[search_hash_index] != NULL && customers[search_hash_index]->getID() != search_id) {
        i++;
        search_hash_index = ((search_id % CUSTOMER_CAPACITY) + i) % CUSTOMER_CAPACITY;
    }
    if (customers[search_hash_index] == NULL) {
        return NULL;
    }
    else if (customers[search_hash_index]->getID() == search_id) return customers[search_hash_index];
    return NULL;
}

//----------------------------------- doAction ----------------------------------------
// Takes in an input file of text designating action types, and data relevant to those 
// action types, calls createAction() in actionfactory, which will construct each 
// action object then will call the execute function of each action
// Preconditions: A store object and valid input file
// Postconditions: Various changes to movie quanitities should there be valid borrow
// and return commands
bool Store::doActions(ifstream& infile) {
    string line; 
    ActionFactory action_doer = ActionFactory(this);
    while (getline(infile, line)) {
        action_doer.initiateAction(line);
    }
    return true;
}

/*
*------------------------------------ ACCESSORS ---------------------------------------
*/
//--------------------------------- getComedyInv --------------------------------------
// Retrieve a reference for this store's inventory of comedy movies
// Preconditions: None
// Postconditions: A reference for this store's inventory of comedy movies
list<Movie*>& Store::getComedyInv() {
    return comedy_inventory;
}

//---------------------------------- getDramaInv --------------------------------------
// Retrieve a reference for this store's inventory of drama movies
// Preconditions: None
// Postconditions: A reference for this store's inventory of drama movies
list<Movie*>& Store::getDramaInv() {
    return drama_inventory;
}

//--------------------------------- getClassicInv -------------------------------------
// Retrieve a reference for this store's inventory of classic movies
// Preconditions: None
// Postconditions: A reference for this store's inventory of classic movies
list<Movie*>& Store::getClassicInv() {
    return classic_inventory;
}

//------------------------------ displayInventories -----------------------------------
// Print the inventories to terminal  
// Preconditions: None
// Postconditions: Inventory outputted to terminal
void Store::displayInventories() {
    list<Movie*>::iterator it;
    cout << "Comedy: " << endl; 
    for (it = comedy_inventory.begin(); it != comedy_inventory.end(); it++) {
        cout << (*it)->getData() << endl;
    }
    cout << "Drama: " << endl;
    for (it = drama_inventory.begin(); it != drama_inventory.end(); it++) {
        cout << (*it)->getData() << endl;
    } 
    cout << "Classic: " << endl;   
    for (it = classic_inventory.begin(); it != classic_inventory.end(); it++) {
        cout << (*it)->getData() << endl;
    }
}

//------------------------------- displayCustomers ------------------------------------
// Print the customers to terminal  
// Preconditions: None
// Postconditions: Customers outputted to terminal
void Store::displayCustomers() {
    for (int i = 0; i < CUSTOMER_CAPACITY; i++) {
        if (customers[i] != NULL) {
            cout << i << ": ";
            customers[i]->displayCustomer();
            cout << endl;
        }
    }
}