#ifndef USER_PREFERENCES_H
#define USER_PREFERENCES_H

#include <string>
#include <vector>
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
    void addMovieToFav(std::string); // adds movies to favourites
    void printFavMovies(); // prints user's fav movies
    void removeMovieFromFavourites(std::string title); // deletes movies from title
};

#endif