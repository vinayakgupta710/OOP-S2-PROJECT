#include <iostream>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"

int main(){
     User_preferences user1;
     user1.checkCredentials();
     user1.removeMovieFromFavourites("Avengers: endgame");
     user1.printFavMovies();
     user1.addMovieToFav("Avengers: endgame");
     return 0;
}