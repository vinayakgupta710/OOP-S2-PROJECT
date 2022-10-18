#include "Ratings_preferences.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Movies_database.h"
#include "Preferences.h"
#include "User_details.h"
#include "User_preferences.h"

// default constructor
Ratings_preferences::Ratings_preferences() {
  avgRatings = 0;
  ratingsScore = 0;
}

void Ratings_preferences::updateUserPreference(std::string username, std::string password) {
  ratingsScore = 0;
  Ratings_preferences* tempRatings = new Ratings_preferences;
  tempRatings->checkCredentials(username, password);

  // getting the fav movie list
  Movies_database** favMovieList = new Movies_database*[favMovies.size()];
  for (int i = 0; i < favMovies.size(); i++) {
    favMovieList[i] = new Movies_database;
  }

  for (int i = 0; i < favMovies.size(); i++) {
    Movies_database tempMovie;
    std::string title = favMovies.at(i);
    favMovieList[i] = tempMovie.fetchMovie(title);
  }

  for (int i = 0; i < favMovies.size(); i++) {
    float tempRatings = favMovieList[i]->getRating();
    ratings.push_back(tempRatings);
  }

  delete[] favMovieList;

  // calculating the avgratings of the fav movie
  float sum = 0;
  for (int i = 0; i < favMovies.size(); i++) {
    sum += ratings.at(i);
  }
  avgRatings = sum / favMovies.size();
}

void Ratings_preferences::calculatePreferenceScore(std::string title) {
  Movies_database* movie_object = new Movies_database;
  // calculating score based on the rating of the movie
  movie_object = movie_object->fetchMovie(title);
  float rating = movie_object->getRating();
  if (rating <= (avgRatings + 1) && rating >= (avgRatings - 1)) {
    ratingsScore += 10;
  } else if (rating <= (avgRatings + 2) && rating >= (avgRatings - 2)) {
    ratingsScore += 5;
  } else if (rating <= (avgRatings + 3) && rating >= (avgRatings - 3)) {
    ratingsScore += 2;
  }

  delete movie_object;
}

int Ratings_preferences::getScore() { return ratingsScore; }