#include <iostream>
#include <string>
#include "Movies_database.h"


int main(){
    Movies_database* movie = new Movies_database;
    std::string title;
    std::cout << "Enter a movie name: ";
    getline(std::cin, title);
    movie = movie->fetchMovie(title);
    std::string name = movie->getTitle();

    std::cout << std::endl << "Title of the movie: " << movie->getTitle() << std::endl;
    std::cout << "Release year of the movie: " << movie->getReleaseYear() << std::endl;
    std::cout << "Rating of the movie (as per TMDb): " << movie->getRating() << std::endl;
    std::cout << "Production stduio of the movie: " << movie->getStudio() << std::endl;
    std::cout << "Genres of the movie: ";
    std::string *genres = movie->getGenreList();
    for(int i = 0; i < movie->getNumOfGenres(); i++){
        if(i < movie->getNumOfGenres() - 1){
            std::cout << *(genres + i) << ", ";
        } else {
            std::cout << *(genres + i) << std::endl;
        }
    }

    return 0;
}