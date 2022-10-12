#ifndef USER_DETAILS_H
#define USER_DETAILS_H

#include <string>
#include "Movies_database.h"

class User_details{
protected:
    std::string password;
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
    //checking credentials for the username and password
    bool checkCredentials(std::string testUserName, std::string testPassword);
    //getter
    std::string getUsername();
    std::string getPassword();
    void logOut();
};

#endif