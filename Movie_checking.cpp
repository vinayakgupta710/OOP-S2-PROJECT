#include <iostream>
#include <map>
#include <string>
#include "Movie_checking.h"
#include "Genre_preferences.h"
#include "Movies_database.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"
#include "Studio_preferences.h"
#include "User_details.h"
#include "User_preferences.h"

// default constructor
Movie_checking::Movie_checking() {
  movie1Score = 0;
  movie2Score = 0;
}

// checks if a movie is worth watching and returns the score and the title of the movie
std::pair<int, std::string> Movie_checking::checkMovieWorthWatching(std::string title, std::string username, std::string password, Movie_checking user) {

  int finalScore = 0;
  // changing the title to new title if it does not exist
  Movies_database* tempMovie = new Movies_database;
  if (!tempMovie->isMovieInDatabase(title)) {
    std::cout << std::endl;
    std::cout << title << " does not exist in the database." << std::endl;
    std::cout << "Do you wish to add it in the database or would like to find "
                 "another movie?"
              << std::endl;
    std::cout << "Type 'y' if you want to add it or 'n' if you would like to "
                 "find another movie: ";
    char addMovieOrContinue;
    std::string userTempInput;
    std::cin >> userTempInput;
    addMovieOrContinue = userTempInput[0];
    addMovieOrContinue = tolower(addMovieOrContinue);
    // calling until the user enters y or n
    while (addMovieOrContinue != 'y' && addMovieOrContinue != 'n') {
      std::cout << std::endl;
      std::cout << "Only y or n character is allowed: ";
      std::cin >> userTempInput;
      addMovieOrContinue = userTempInput[0];
      addMovieOrContinue = tolower(addMovieOrContinue);
    }
    // calling the add function if the user enters y
    if (addMovieOrContinue == 'y') {
      std::cin.ignore();
      std::cout << std::endl;
      tempMovie->addMovie();
    } else {  // calling the same funciton with a different title if the user
              // enters n
      std::string newTitle;
      std::cout << std::endl;
      std::cout << "Enter the new title of the movie that you want to fetch "
                   "information of: ";
      std::cin.ignore();
      getline(std::cin, newTitle);
      title = newTitle;
    }
  }
  delete tempMovie;

  // adding the scores calculated using different classes to the final score
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
 
  // creates a pair of the score and movie title
  std::pair<int, std::string> movieScoreAndTitle;
  movieScoreAndTitle.first = finalScore;
  movieScoreAndTitle.second = title;

  return movieScoreAndTitle;
}


// checks if a movie is worth watching 
bool Movie_checking::movieWorthy(int score) {
  // checks if a movie is worth watching
  if (score > 30) {
    return true;
  }
  return false;
}

// compares two movies
void Movie_checking::compareMovies(std::string title1, std::string title2, std::string username, std::string password, Movie_checking user) {
  // calling check func and prints the movie that the user should watch
  std::pair<int, std::string> movie1 =
      checkMovieWorthWatching(title1, username, password, user);
  std::pair<int, std::string> movie2 =
      checkMovieWorthWatching(title2, username, password, user);

  if (movie1.first > movie2.first) {
    std::cout << "You should watch " + movie1.second << std::endl;
  } else if (movie1.first < movie2.first) {
    std::cout << "You should watch " + movie2.second << std::endl;
  } else {
    std::cout << "You can watch either of the movie" << std::endl;
  }
}