#ifndef USER_PREFERENCES_H
#define USER_PREFERENCES_H

#include <string>
#include <vector>
#include "Preferences.h"
#include "User_details.h"
#include "Movies_database.h"

class User_preferences: public User_details{
protected:
    std::vector<std::string> genrePref; // array of user's fav genres
    std::vector<int> ratingPref; // array of user's fav ratings
    std::vector<int> releaseYearPref; // array of user's fav release years
    std::vector<std::string> studioPref; // array of user's fav studios
    std::vector<std::string> favMovies; // array of user's fav movies
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
};

#endif