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

bool Movie_checking::checkMovieWorthWatching(std::string title, Movie_checking user){
    bool movie_worthy = false;
    int finalScore = 0;

    user.Genre_preferences::updateUserPreference();
    user.Genre_preferences::calculatePreferenceScore(title);
    int genreScore = user.Genre_preferences::getScore();
    finalScore += genreScore;

    user.Ratings_preferences::updateUserPreference();
    user.Ratings_preferences::calculatePreferenceScore(title);
    int ratingScore = user.Ratings_preferences::getScore();
    finalScore += ratingScore;

    std::cout << finalScore << std::endl;

    return movie_worthy;
}