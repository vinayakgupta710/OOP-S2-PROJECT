#ifndef MOVIE_CHECKING_H
#define MOVIE_CHECKING_H

#include <iostream>
#include <map>
#include <string>

#include "Genre_preferences.h"
#include "Movies_database.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"
#include "Studio_preferences.h"
#include "User_details.h"
#include "User_preferences.h"

class Movie_checking : public virtual User_details,
                       public virtual User_preferences,
                       public Genre_preferences,
                       public Studio_preferences,
                       public Ratings_preferences,
                       public Release_year_preferences {
 private:
  int movie1Score;  // score for the first movie
  int movie2Score;  // score for the second movie
 public:
  Movie_checking();  // default constructor
  std::pair<int, std::string> checkMovieWorthWatching(
      std::string, std::string, std::string,
      Movie_checking);  // calculates the score
  bool movieWorthy(
      int score);  // checks if movie is worth watching by comparing the score
                   // compares two movies
  void compareMovies(std::string title1, std::string title2, std::string,
                     std::string, Movie_checking);
};

#endif