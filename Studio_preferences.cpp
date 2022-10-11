#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Studio_preferences.h"

Studio_preferences::Studio_preferences(){
    studioScore = 0;
}

void Studio_preferences::updateUserPreference(){
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
        std::string tempStudio = favMovieList[i]->getStudio();
        studios.push_back(tempStudio);
    }

    delete[] favMovieList;
}

void Studio_preferences::calculatePreferenceScore(std::string title){
    Movies_database* movie_object = new Movies_database;

    movie_object = movie_object->fetchMovie(title);
    std::string studio = movie_object->getStudio();
    
    int count = 0;

    for(int i = 0; i < studios.size(); i++){
        if(studio == studios.at(i)){
            count++;
        }
    }

    studioScore += (count * 2);

    delete movie_object;
}

int Studio_preferences::getScore(){ return studioScore; }