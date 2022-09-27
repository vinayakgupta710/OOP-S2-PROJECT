#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "User_details.h"

User_details::User_details(){
    username = "";
    password = "";
    userID = 0;    
}

bool User_details::checkCredentials(){
    // taking in input from the user for his username and password
    std::string testUserName;
    std::cout << "Please enter your username: ";
    std::cin >> testUserName;

    std::string testPassword;
    std::cout << "Please enter your password: ";
    std::cin >> testPassword;

    

}