#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Release_year_preferences.h"

Release_year_preferences::Release_year_preferences(){
    avgReleaseYear = 0;
}

void Release_year_preferences::updateUserPreference(){
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
        int tempYear = favMovieList[i]->getReleaseYear();
        releaseYear.push_back(tempYear);
    }

    delete[] favMovieList;
    float sum = 0; 
    for(int i = 0; i < favMovies.size(); i++){
        sum += releaseYear.at(i);
    }
    avgReleaseYear = sum / favMovies.size();
}

void Release_year_preferences::calculatePreferenceScore(){

}