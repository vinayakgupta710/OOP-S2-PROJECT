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
    std::string title1 = "Avengers: endgame";
    std::string title2 = "Interstellar";
    std::string title = "Inception";
    
    bool worthy = user1.movieWorthy(user1.checkMovieWorthWatching(title2, username, password, user1));
    if(worthy == true){
        std::cout << "You can watch " + title2 << std::endl;
    }
    std::cout << "------------" << std::endl;
    user1.compareMovies(title, title1, username, password, user1);
    
    return 0;
}