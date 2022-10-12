#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    Movies_database* movie = new Movies_database;
    movie = movie->fetchMovie("Avengers: endgame");
    std::string* genres = movie->getGenreList();
    for(int i = 0; i < movie->getNumOfGenres(); i++){
        std::cout << genres[i] << std::endl;
    }

    return 0;
}