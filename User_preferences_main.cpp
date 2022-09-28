#include <iostream>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"

int main(){
    User_preferences user1;
    user1.checkCredentials();
    std::string title = "Zindagi na Milegi Dobara";
    user1.addMovieToFav(title);

    return 0;
}