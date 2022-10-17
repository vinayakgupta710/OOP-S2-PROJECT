#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Ratings_preferences.h"

int main(){
    Ratings_preferences user1;
    user1.checkCredentials();
    user1.printFavMovies();
    std::string username = user1.getUsername();
    std::string password = user1.getPassword();

    user1.updateUserPreference(username, password);
    user1.calculatePreferenceScore("Avengers: endgame");

    std::cout << user1.getScore() << std::endl;
    

    return 0;
}