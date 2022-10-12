#ifndef MOVIE_CHECKING_H
#define MOVIE_CHECKING_H

#include <iostream>
#include <string>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Genre_preferences.h"
#include "Studio_preferences.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"

class Movie_checking: public virtual User_details, public virtual User_preferences, public Genre_preferences, public Studio_preferences, public Ratings_preferences, public Release_year_preferences{
private:
    int movie1Score;
    int movie2Score;
public:
    Movie_checking(); // default constructor
    int checkMovieWorthWatching(std::string, std::string, std::string, Movie_checking); // checks if the movie is worth watching
    bool movieWorthy(int score); // checks if movie is worth watching by comparing the score
    void compareMovies(std::string title1, std::string title2, std::string, std::string, Movie_checking); 
};

#endif