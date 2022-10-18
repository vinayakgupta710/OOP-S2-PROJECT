#include "Release_year_preferences.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Movies_database.h"
#include "Preferences.h"
#include "User_details.h"
#include "User_preferences.h"

// default construcotr
Release_year_preferences::Release_year_preferences() {
  avgReleaseYear = 0;
  releaseYearScore = 0;
}

void Release_year_preferences::updateUserPreference(std::string username,
                                                    std::string password) {
  releaseYearScore = 0;
  Release_year_preferences* tempReleaseYear = new Release_year_preferences;
  tempReleaseYear->checkCredentials(username, password);

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
    int tempYear = favMovieList[i]->getReleaseYear();
    releaseYear.push_back(tempYear);
  }

  delete[] favMovieList;

  // getting the avg release year
  float sum = 0;
  for (int i = 0; i < favMovies.size(); i++) {
    sum += releaseYear.at(i);
  }
  avgReleaseYear = sum / favMovies.size();
}

void Release_year_preferences::calculatePreferenceScore(std::string title) {
  Movies_database* movie_object = new Movies_database;

  movie_object = movie_object->fetchMovie(title);
  int releaseYear = movie_object->getReleaseYear();

  if (releaseYear <= (avgReleaseYear + 5) &&
      releaseYear >= (avgReleaseYear - 5)) {
    releaseYearScore += 10;
  } else if (releaseYear <= (avgReleaseYear + 10) &&
             releaseYear >= (avgReleaseYear - 10)) {
    releaseYearScore += 5;
  }

  delete movie_object;
}

int Release_year_preferences::getScore() { return releaseYearScore; }