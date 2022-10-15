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
    std::cout << "Enter 'logout' at any point if you wanna logout of the system: ";
    std::cin >> userInput;

    // creating a new user 
    Movie_checking user;

    while(userInput != "exit" || userInput != "login" || userInput != "signin"){
        // callign the check credentials functions if the user enters login
        if(userInput == "login"){
            std::cout << std::endl;
            user.checkCredentials();
            break;
        } else if(userInput == "signin"){ // calling addnewuser function if user enters signin
            std::cout << std::endl;
            user.addNewUser();
            std::cout << "New user successfully created!" << std::endl;
            std::cout << "You need to enter the details again to successfully login." << std::endl;
            user.checkCredentials();
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





    return 0;
}