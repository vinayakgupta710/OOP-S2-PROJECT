#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    std::string genre = "Comedy";
    Movies_database movie("title", 4, 2020, &genre, "Disney", 9.9, 11);
    Movies_database* newMovie;
    newMovie = movie.fetchMovie("The Dark Knight rises");

    std::cout << newMovie->getTitle() << std::endl;
    return 0;
}