#include <iostream>
#include <string>

#include "Genre_preferences.h"
#include "Movie_checking.h"
#include "Movies_database.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"
#include "Studio_preferences.h"
#include "User_details.h"
#include "User_preferences.h"

int main() {
  // creating a title screen
  std::cout << "---------------------------------------------------------------"
               "----------------------"
            << std::endl;
  std::cout << "--------------------------------------|MOVIE "
               "RECOMMENDER|----------------------------"
            << std::endl;
  std::cout << "---------------------------------------------------------------"
               "----------------------"
            << std::endl;
  std::cout << std::endl;

  // getting the input from the user about whether they want to log in or sign
  // in
  std::string userInput;
  std::cout << "Enter 'login' if you are an existing user or enter 'signin' if "
               "you are a new user:"
            << std::endl;
  std::cout << "Enter 'logout' if you wanna logout of the system: ";
  std::cin >> userInput;

  // creating a new user
  Movie_checking user;
  std::string username;
  std::string password;

  while (userInput != "logout" || userInput != "login" ||
         userInput != "signin") {
    // callign the check credentials functions if the user enters login
    if (userInput == "login") {
      std::cout << std::endl;
      user.checkCredentials();
      username = user.getUsername();
      password = user.getPassword();
      break;
    } else if (userInput ==
               "signin") {  // calling addnewuser function if user enters signin
      std::cout << std::endl;
      user.addNewUser();
      std::cout << "New user successfully created!" << std::endl;
      std::cout << "You need to enter the details again to successfully login."
                << std::endl;
      user.checkCredentials();
      username = user.getUsername();
      password = user.getPassword();
      break;
    } else if (userInput == "logout") {
      std::cout << "System exited!" << std::endl;
      user.logOut();
      return 0;
    } else {  // invalid input asking to write again
      std::cout << std::endl;
      std::cout << "Invalid input! Please try again" << std::endl;
      std::cout << "Enter 'login' if you are an existing user or enter "
                   "'signin' if you are a new user:"
                << std::endl;
      std::cout << "Enter 'exit' at any point if you wanna exit the system: ";
      std::cin >> userInput;
    }
  }

  // printing user's fav movie
  std::cout << std::endl;
  user.printFavMovies();
  std::cout << std::endl;

  // printing help commands
  std::cout << "Please choose one of the following options: " << std::endl;
  std::cout << "Enter 'info' to display the information about the movie"
            << std::endl;
  std::cout << "Enter 'add' if you wanna add a movie to your favourites"
            << std::endl;
  std::cout << "Enter 'remove' if you wanna remove a movie from your favourites"
            << std::endl;
  std::cout << "Enter 'print' to print your list of favourite movies"
            << std::endl;
  std::cout << "Enter 'compare' if you wanna compare two movies and check "
               "which one is better to watch"
            << std::endl;
  std::cout << "Enter 'check' if you wanna check if a movie is worth watching"
            << std::endl;
  std::cout << "Enter 'logout' if you wanna log out of the system" << std::endl;
  std::cout << "Enter 'help' to display these options again" << std::endl;
  std::cout << "Enter input here: ";
  std::cin >> userInput;

  // would run until the user enters logout
  while (true) {
    if (userInput == "remove") {  // removing the user's fav movie
      std::string title;
      std::cout << std::endl;
      std::cout << "Enter the title of the movie that you wanna remove from "
                   "your favourites: ";
      std::cin.ignore();
      getline(std::cin, title);
      user.checkCredentials(username, password);
      user.removeMovieFromFavourites(title);
      user.printFavMovies();
      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else if (userInput == "add") {  // adding a movie to user's fav
      std::string title;
      std::cout << std::endl;
      std::cout << "Enter the title of the movie that you wanna add to your "
                   "favourites: ";
      std::cin.ignore();
      getline(std::cin, title);
      user.checkCredentials(username, password);
      user.addMovieToFav(title);
      user.printFavMovies();
      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else if (userInput == "info") {  // fetching info about a movie
      Movies_database* tempMovie = new Movies_database;
      std::string title;
      std::cout << std::endl;
      std::cout
          << "Enter the title of the movie that you wanna find info about: ";
      std::cin.ignore();
      getline(std::cin, title);

      tempMovie = tempMovie->fetchMovie(title);
      std::cout << std::endl
                << "Title of the movie: " << tempMovie->getTitle() << std::endl;
      std::cout << "Release year of the movie: " << tempMovie->getReleaseYear()
                << std::endl;
      std::cout << "Rating of the movie (as per TMDb): "
                << tempMovie->getRating() << std::endl;
      std::cout << "Production stduio of the movie: " << tempMovie->getStudio()
                << std::endl;
      std::cout << "Genres of the movie: ";
      std::string* genres = tempMovie->getGenreList();
      for (int i = 0; i < tempMovie->getNumOfGenres(); i++) {
        if (i < tempMovie->getNumOfGenres() - 1) {
          std::cout << *(genres + i) << ", ";
        } else {
          std::cout << *(genres + i) << std::endl;
        }
      }
      delete tempMovie;

      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else if (userInput == "check") {  // checking if a movie is worth watching
      std::string title;
      std::cout << std::endl;
      std::cout << "Enter the title of the movie that you wish to check "
                   "whether its worth watching: ";
      std::cin.ignore();
      getline(std::cin, title);
      std::pair<int, std::string> pairOfMovie =
          user.checkMovieWorthWatching(title, username, password, user);
      int score = pairOfMovie.first;
      bool movieWatch = user.movieWorthy(score);
      if (movieWatch == true) {
        std::cout << "You should watch " << pairOfMovie.second << std::endl;
      } else {
        std::cout << "You should not watch " << pairOfMovie.second << std::endl;
      }
      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else if (userInput ==
               "compare") {  // comparing two movies and tells which to watch
      std::string title1;
      std::string title2;
      std::cout << std::endl;
      std::cout << "Enter the title for the first movie: ";
      std::cin.ignore();
      getline(std::cin, title1);
      std::cout << "Enter the title for the second movie: ";
      getline(std::cin, title2);
      user.compareMovies(title1, title2, username, password, user);
      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else if (userInput == "logout") {  // logs out the user
      std::cout << "Logged out for " << username << std::endl;
      user.logOut();
      return 0;

    } else if (userInput == "help") {  // displayes the help command again
      std::cout << "Please choose one of the following options: " << std::endl;
      std::cout << "Enter 'add' if you wanna add a movie to your favourites"
                << std::endl;
      std::cout
          << "Enter 'remove' if you wanna remove a movie from your favourites"
          << std::endl;
      std::cout << "Enter 'print' to print your list of favourite movies"
                << std::endl;
      std::cout
          << "Enter 'check' if you wanna check if a movie is worth watching"
          << std::endl;
      std::cout << "Enter 'compare' if you wanna compare two movies and check "
                   "which one is better to watch"
                << std::endl;
      std::cout << "Enter 'logout' if you wanna log out of the system"
                << std::endl;
      std::cout << "Enter 'help' to display these options again" << std::endl;
      std::cout << "Enter input here: ";
      std::cin >> userInput;

    } else if (userInput == "print") {  // prints the user's fav movies
      std::cout << std::endl;
      user.printFavMovies();
      std::cout << std::endl;
      std::cout << "Choose from the options again (type 'help' to view the "
                   "options): ";
      std::cin >> userInput;

    } else {  // displayes the commands again if invalid input
      std::cout << "Invalid input!" << std::endl << std::endl;
      std::cout << "Please choose one of the following options: " << std::endl;
      std::cout << "Enter 'add' if you wanna add a movie to your favourites"
                << std::endl;
      std::cout
          << "Enter 'remove' if you wanna remove a movie from your favourites"
          << std::endl;
      std::cout << "Enter 'print' to print your list of favourite movies"
                << std::endl;
      std::cout
          << "Enter 'check' if you wanna check if a movie is worth watching"
          << std::endl;
      std::cout << "Enter 'compare' if you wanna compare two movies and check "
                   "which one is better to watch"
                << std::endl;
      std::cout << "Enter 'logout' if you wanna log out of the system"
                << std::endl;
      std::cout << "Enter 'help' to display these options again" << std::endl;
      std::cout << "Enter input here: ";
      std::cin >> userInput;
    }
  }

  return 0;
}