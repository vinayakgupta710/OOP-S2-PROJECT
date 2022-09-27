#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "User_details.h"

// default constructor set everything to 0/null
User_details::User_details(){
    username = "";
    password = "";
    userID = 0;    
}

bool User_details::IsUsernameUsed(std::string usernameTrial){
    // setting the bool value to false by default
    bool inDatabase = false;
    const std::string filename = "user_details_cpp_dataset.csv";

    // reading the csv file
    std::ifstream userDatabase(filename);
    // reading the file line by line and extracting the username which matches the arg
    std::string tempUsername;
    for(std::string line; getline(userDatabase, line); ){
        // using find() function to check if the title is present in the row of the csv
        if(line.find(usernameTrial) != std::string::npos){
                std::stringstream userDetailsInParts(line);
                std::string separatedLine;
                int count = 0;
                while(std::getline(userDetailsInParts, separatedLine, ',')){
                    if(count == 1){
                        tempUsername = separatedLine;
                        // turning the bool value to true if username is found
                        if(usernameTrial == tempUsername){
                            inDatabase = true;
                        }
                    }
                    count++;
                }
        }
    }

    return inDatabase;
}

// checks the user if the username and password is correct. returns true/false
bool User_details::checkCredentials(){
    bool loggedIn = false;
    const std::string filename = "user_details_cpp_dataset.csv";
    std::string* userDetailsArr = new std::string[4];

    // taking in input from the user for his username and password
    std::string testUserName;
    std::cout << "Please enter your username: ";
    std::cin >> testUserName;

    std::string testPassword;
    std::cout << "Please enter your password: ";
    std::cin >> testPassword;

    // if username does not exist, call add a new user otherwise check credentials
    if(!IsUsernameUsed(testUserName)){
        std::cout << "User does not exist!" << std::endl;
        std::cout << "Try creating a new profile instead... " << std::endl;
        loggedIn = false;
        //addNewUser();
    } else if (IsUsernameUsed(testUserName)) {
        std::cout << "Checking credentials... " << std::endl;

        // opening the file stream for userDatabase
        std::ifstream userDatabase(filename);

        // reading the file line by line and extracting the username which matches the arg
        for(std::string line; getline(userDatabase, line); ){
            // using find() function to check if the title is present in the row of the csv
            if(line.find(testUserName) != std::string::npos){
                std::stringstream userDetailsInParts(line);
                std::string separatedLine;
                int i = 0; // iterator for user details
                while(std::getline(userDetailsInParts, separatedLine, ',')){
                    userDetailsArr[i] = separatedLine;
                    i++;
                }
                break;
            }
        }

        int j = 1;
        std::string actualUsername  = userDetailsArr[j];
        j++;
        std::string actualPassword = userDetailsArr[j];

        delete[] userDetailsArr;

        if(testUserName == actualUsername && testPassword == actualPassword){
            loggedIn = true;
            std::cout << "Successfully logged in for " << actualUsername << " " << std::endl;
        } else {
            loggedIn = false;
            std::cout << "Invalid Credentials!" << std::endl;
        }
    }
    return loggedIn;
}