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


int main(){
    Movie_checking user1;
    user1.checkCredentials();
    std::string username = user1.getUsername();
    std::string password = user1.getPassword();
    user1.checkMovieWorthWatching("Avengers: endgame", username, password, user1);
    
    return 0;
}