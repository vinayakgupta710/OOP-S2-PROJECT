#ifndef USER_DETAILS_H
#define USER_DETAILS_H

#include <string>

class User_details{
private:
    std::string username;
    std::string password;
protected:
    int userID;
public:
    User_details(); // constructor for user details
    // adds a new user to the database by asking for their username and password
    // checks if its alr taken or not
    // adds the user and assigns a userID itself 
    // asks for user's favourite movies and adds in the database
    bool addNewUser(); 
    // asks for user's username and password and lets them enter if its correct
    bool checkCredentials();
};

#endif