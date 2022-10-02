#include <iostream>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"

int main(){
    User_preferences user1;
    std::cout << "\t\t\t\t\t\t\t | WELCOME TO MOVIE RECOMMENDOR | " << std::endl;
    std::cout << std::endl;
    std::cout << "This system helps you manage your favourite movies in one place while simultaneously helping you decide which movie to watch. " << std::endl;
    std::cout << std::endl;
    std::cout << "Do you wish to login or sign up?" << std::endl;
    std::cout << "Enter 'login' login to login and 'signup' to signup: login" << std::endl;
    user1.checkCredentials();
    std::cout << std::endl;
    user1.printFavMovies();
    std::cout << std::endl;
    std::cout << "Would you like to compare two movies or check if the a movie is worth your time? " << std::endl;
    std::cout << "Enter 'compare' for comparing and 'worthy' for the latter: " << std::endl;
    std::cout << "Enter 'other' to see more options: ";
    std::string input;
    std::cin>>input;

    return 0;
}