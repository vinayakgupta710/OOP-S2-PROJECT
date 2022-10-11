#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Genre_preferences.h"

Genre_preferences::Genre_preferences(){
    genres.push_back("action");
    genres.push_back("adventure");
    genres.push_back("animation");
    genres.push_back("horror");
    genres.push_back("comedy");
    genres.push_back("crime");
    genres.push_back("drama");
    genres.push_back("fantasy");
    genres.push_back("romance");
    genres.push_back("thriller");
    genres.push_back("mystery");
    genres.push_back("science fiction");
    genres.push_back("documentary");

    for(int i = 0; i < genres.size(); i++){
        genreOccurences.push_back(0);
    }

    genresScore = 0;
}

void Genre_preferences::updateUserPreference(){
    Movies_database** favMovieList = new Movies_database*[favMovies.size()];
    for(int i = 0; i < favMovies.size(); i++){
        favMovieList[i] = new Movies_database;
    }

    for(int i = 0; i < favMovies.size(); i++){
        Movies_database tempMovie;
        std::string title = favMovies.at(i);
        favMovieList[i] = tempMovie.fetchMovie(title);
    }

    for(int i = 0; i < favMovies.size(); i++){
        std::string* tempGenres = favMovieList[i]->getGenreList();
        std::cout << tempGenres[0] << std::endl;
    }

    delete[] favMovieList;
}

void Genre_preferences::calculatePreferenceScore(std::string title){
}

int Genre_preferences::getScore(){ return genresScore; }