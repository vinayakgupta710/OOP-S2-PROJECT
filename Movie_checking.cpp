#include <iostream>
#include <string>
#include "Movie_checking.h"
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Genre_preferences.h"
#include "Studio_preferences.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"

Movie_checking::Movie_checking(){
    movie1Score = 0;
    movie2Score = 0;
}

bool Movie_checking::checkMovieWorthWatching(std::string title, std::string username, std::string password, Movie_checking user){
    bool movie_worthy = false;
    
    int finalScore = 0;
    user.getFavMovies(username);
    user.Genre_preferences::updateUserPreference(username, password);
    user.Genre_preferences::calculatePreferenceScore(title);
    int genreScore = user.Genre_preferences::getScore();
    finalScore += genreScore;

    user.getFavMovies(username);
    user.Ratings_preferences::updateUserPreference(username, password);
    user.Ratings_preferences::calculatePreferenceScore(title);
    int ratingScore = user.Ratings_preferences::getScore();
    finalScore += ratingScore;

    user.getFavMovies(username);
    user.Release_year_preferences::updateUserPreference(username, password);
    user.Release_year_preferences::calculatePreferenceScore(title);
    int releaseYearScore = user.Release_year_preferences::getScore();
    finalScore += releaseYearScore;

    user.getFavMovies(username);
    user.Studio_preferences::updateUserPreference(username, password);
    user.Studio_preferences::calculatePreferenceScore(title);
    int studioScore = user.Studio_preferences::getScore();
    finalScore += studioScore;

    if(finalScore > 30){
        movie_worthy = true;
    }

    return movie_worthy;
}