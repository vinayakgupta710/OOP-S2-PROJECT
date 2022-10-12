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

class Movie_checking: public virtual User_details, public virtual User_preferences, public virtual Genre_preferences, public virtual Studio_preferences, public virtual Ratings_preferences, public virtual Release_year_preferences{
private:
    int movie1Score;
    int movie2Score;
public:
    Movie_checking(); // default constructor
    bool checkMovieWorthWatching(std::string, Movie_checking); // checks if the movie is worth watching
    bool movieWorthy(int score); // checks if movie is worth watching by comparing the score
    Movies_database compareMovies(std::string title1, std::string title2); 
};

#endif