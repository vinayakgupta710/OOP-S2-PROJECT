#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Genre_preferences.h"

int main(){
    Genre_preferences user1;
    user1.checkCredentials();
    user1.printFavMovies();
    
    user1.updateUserPreference();
    //user1.calculatePreferenceScore("Avengers: endgame");

    std::cout << user1.getScore() << std::endl;
    

    return 0;
}