#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Release_year_preferences.h"

int main(){
    Release_year_preferences user1;
    user1.checkCredentials();
    user1.printFavMovies();

    user1.calculatePreferenceScore("Avengers: endgame");

    return 0;
}