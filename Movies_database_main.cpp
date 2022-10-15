#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    Movies_database* movie = new Movies_database;
    movie = movie->fetchMovie("Spider-Man: No Way Home");
    std::string name = movie->getTitle();
    std::cout << name << std::endl;

    return 0;
}