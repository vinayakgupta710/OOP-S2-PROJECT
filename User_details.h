#ifndef USER_DETAILS_H
#define USER_DETAILS_H

#include <string>
#include "Movies_database.h"

class User_details{
private:
    std::string password; // password of the user
protected:
    std::string username; // username of the user (unique)
    int userID; // user id of the user (unique)
public:
    User_details(); // constructor for user details
    // adds a new user to the database by asking for their username and password
    // checks if its alr taken or not
    // adds the user and assigns a userID itself 
    // asks for user's favourite movies and adds in the database
    bool addNewUser(); 
    // asks for user's username and password and lets them enter if its correct
    bool checkCredentials();
    // checks if the username already exists
    bool IsUsernameUsed(std::string usernameTrial);
    void logOut();
};

#endif