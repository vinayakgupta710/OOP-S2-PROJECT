#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    std::string genre = "Comedy";
    Movies_database movie("title", 2020, &genre, "Disney", 9.9, 11);

    movie.addMovie();

    return 0;
}