#include <iostream>
#include <string>
#include "Movie_checking.h"
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Genre_preferences.h"
#include "Studio_preferences.h"
#include "Ratings_preferences.h"
#include "Release_year_preferences.h"
#include "Movie_checking.h"

int main(){
    // creatign a title screen
    std::cout << "-------------------------------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------|MOVIE RECOMMENDER|----------------------------" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    // getting the input from the user about whether they want to log in or sign in 
    std::string userInput;
    std::cout << "Enter 'login' if you are an existing user or enter 'signin' if you are a new user:" << std::endl;
    std::cout << "Enter 'logout' if you wanna logout of the system: ";
    std::cin >> userInput;

    // creating a new user 
    Movie_checking user;
    std::string username;
    std::string password;

    while(userInput != "logout" || userInput != "login" || userInput != "signin"){
        // callign the check credentials functions if the user enters login
        if(userInput == "login"){
            std::cout << std::endl;
            user.checkCredentials();
            username = user.getUsername();
            password = user.getPassword();
            break;
        } else if(userInput == "signin"){ // calling addnewuser function if user enters signin
            std::cout << std::endl;
            user.addNewUser();
            std::cout << "New user successfully created!" << std::endl;
            std::cout << "You need to enter the details again to successfully login." << std::endl;
            user.checkCredentials();
            username = user.getUsername();
            password = user.getPassword();
            break;
        } else if(userInput == "logout"){
            std::cout << "System exited!" << std::endl;
            user.logOut();
            return 0;
        } else { // invalid input asking to write again
            std::cout << std::endl;
            std::cout << "Invalid input! Please try again" << std::endl;
            std::cout << "Enter 'login' if you are an existing user or enter 'signin' if you are a new user:" << std::endl;
            std::cout << "Enter 'exit' at any point if you wanna exit the system: ";
            std::cin >> userInput;
        }
    }

    std::cout << std::endl;
    user.printFavMovies();
    std::cout << std::endl;


    std::cout << "Please choose one of the following options: " << std::endl;
    std::cout << "Enter 'add' if you wanna add a movie to your favourites" << std::endl;
    std::cout << "Enter 'remove' if you wanna remove a movie from your favourites" << std::endl;
    std::cout << "Enter 'check' if you wanna check if a movie is worth watching" << std::endl;
    std::cout << "Enter 'compare' if you wanna compare two movies and check which one is better to watch" << std::endl;
    std::cout << "Enter 'logout' if you wanna log out of the system" << std::endl;;
    std::cout << "Enter input here: ";
    std::cin >> userInput;

    while(userInput != "add" || userInput != "remove" || userInput != "check" || userInput != "compare" || userInput != "logout"){
        if(userInput == "remove"){
            std::string title;
            std::cout << std::endl;
            std::cout << "Enter the title of the movie that you wanna remove from your favourites: ";
            std::cin >> title;
            user.checkCredentials(username, password);
            user.removeMovieFromFavourites(title);
            std::cout << std::endl;
            user.printFavMovies();
            break;
        }
    }

    return 0;
}