#ifndef USER_PREFERENCES_H
#define USER_PREFERENCES_H

#include <string>
#include "Preferences.h"
#include "User_details.h"
#include "Movies_database.h"

class User_preferences: public User_details{
protected:
    std::string* genrePref; // array of user's fav genres
    int* ratingPref; // array of user's fav ratings
    int* releaseYearPref; // array of user's fav release years
    std::string* studioPref; // array of user's fav studios
    Movies_database* favMovies; // array of user's fav movies
public:
    User_preferences(); // default constructor
    bool checkMovieWorthWatching(std::string); // checks if the movie is worth watching
    bool movieWorthy(int score); // checks if movie is worth watching by comparing the score
    void addMovieToFav(std::string); // adds movies to favourites
    void printFavMovies(); // prints user's fav movies
    void removeMovieFromFavourites(std::string title); // deletes movies from title
    // compares two movies inputted by the user and recommends the better movie
    Movies_database compareMovies(std::string title1, std::string title2); 
    // could be deleted
    std::string recommendMovie(); // recommends a random movie
    // destructor
    //~User_preferences();
};

#endif