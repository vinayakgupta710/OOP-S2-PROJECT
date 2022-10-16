#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    Movies_database* movie = new Movies_database;
    std::string title;
    std::cout << "enter: ";
    getline(std::cin, title);
    movie = movie->fetchMovie(title);
    std::string name = movie->getTitle();
    std::cout << "Inside main: " << name << std::endl;

    return 0;
}