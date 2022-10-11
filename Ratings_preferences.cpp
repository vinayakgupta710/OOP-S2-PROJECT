#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Ratings_preferences.h"

Ratings_preferences::Ratings_preferences(){
    avgRatings = 0;
    ratingsScore = 0;
}

void Ratings_preferences::updateUserPreference(){
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
        int tempRatings = favMovieList[i]->getReleaseYear();
        ratings.push_back(tempRatings);
    }

    delete[] favMovieList;
    
    float sum = 0; 
    for(int i = 0; i < favMovies.size(); i++){
        sum += ratings.at(i);
    }
    avgRatings = sum / favMovies.size();
}

void Ratings_preferences::calculatePreferenceScore(std::string title){
    Movies_database* movie_object = new Movies_database;

    movie_object = movie_object->fetchMovie(title);
    int rating = movie_object->getRating();

    if(rating <= (avgRatings + 1) && rating >= (avgRatings - 1)){
        ratingsScore += 10;
    } else if(rating <= (avgRatings + 2) && rating >= (avgRatings - 2)){
        ratingsScore += 5;
    } else if(rating <= (avgRatings + 3) && rating >= (avgRatings - 3)){
        ratingsScore += 2;
    }

    delete movie_object;
}

int Ratings_preferences::getScore(){ return ratingsScore; }