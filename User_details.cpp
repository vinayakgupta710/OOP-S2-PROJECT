#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "User_details.h"
#include "Movies_database.h"

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
        addNewUser();
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
        username  = userDetailsArr[j];
        j++;
        password = userDetailsArr[j];

        

        if(testUserName == username && testPassword == password){
            loggedIn = true;
            userID = stoi(userDetailsArr[0]);
            std::cout << "Successfully logged in for " << username << " " << std::endl;
            // add the functionality that it offers after this

        } else {
            loggedIn = false;
            std::cout << "Invalid Credentials!" << std::endl;
            checkCredentials();
        }
        delete[] userDetailsArr;
    }

    return loggedIn;
}

void User_details::logOut(){
    User_details();
}

bool User_details::addNewUser(){
    const std::string filename = "user_details_cpp_dataset.csv";
    bool userAdded = false;

    std::string newUsername;
    std::cout << "Enter your new username (without spaces): ";
    std::cin >> newUsername;
    std::cin.ignore();

    while(IsUsernameUsed(newUsername)){
        std::cout << "Username already exists!" << std::endl;
        std::cout << "Enter a different username: ";
        std::cin.ignore();
        std::cin >> newUsername;
        std::cin.ignore();
    }
    std::cout << "Your current username is " << newUsername << std::endl;

    std::string newPassword;
    std::cout << "Enter your new password (without spaces): ";
    std::cin >> newPassword;
    std::cin.ignore();
    std::cout << "Your password is set as " << newPassword << std::endl;

    int newUserID = 0;
    // extracting the id from the database and settng the new entry to id+1
    std::ifstream movieDatabaseTemp(filename);
    std::string tempLine;
    while(getline(movieDatabaseTemp, tempLine)){}
    // finding the first word from the tempLine
    std::string userIdInStr;
    int commaIndexInUser = 0;
    for(int i = 0; i < tempLine.length(); i++){
        if(tempLine[i] == ','){
            commaIndexInUser = i;
            break;
        }
    }
    for(int i = 0; i < commaIndexInUser; i++){
        userIdInStr = userIdInStr + tempLine[i];
    }
    newUserID = stoi(userIdInStr);
    newUserID = newUserID + 1;

    std::cout << "As a final step, you need to add 3 of your favourite movies. " << std::endl;    
    std::cout << "This allows us to recommend you better movies by learning about your preferences." << std::endl;
    // getting the input from the user regarding their fav movies and storing it in a single str
    std::string movieArr[3];
    for(int i = 0; i < 3; i++){
        std::string movieTitle;
        std::cout << "Enter movie title " << std::to_string(i+1) << ": ";
        getline(std::cin, movieTitle);
        
        Movies_database movie1;
        while(!movie1.isMovieInDatabase(movieTitle)){
            std::cout << std::endl;
            std::cout << "Make sure you include any punctuations that the movie title includes " << std::endl;
            std::cout << "Movie does not exist in the database." << std::endl;
            std::cout << "Since you are a new user you cannot add any new movies in the database." << std::endl;
            std::cout << "After adding the initial 3 movies in the database, you will have the ability to add the movie in the database." << std::endl;
            std::cout << std::endl;
            std::cout << "Enter a new title that you will like to search for: ";
            getline(std::cin, movieTitle);
        }
        movieArr[i] = movieTitle;
    }

    std::string newFavMovieStr = movieArr[0] + ";" + movieArr[1] + ";" + movieArr[2];

    // adding the details of the new user in the csv file
    std::ofstream userDatabaseOut;
    userDatabaseOut.open(filename, std::ios::app);

    userDatabaseOut << "\n" << std::to_string(newUserID) + "," + newUsername + "," + newPassword +  "," + newFavMovieStr;
    userDatabaseOut.close();
    userAdded = true;

    return userAdded;
}

// checks the user if the username and password is correct. returns true/false
bool User_details::checkCredentials(std::string testUserName, std::string testPassword){
    bool loggedIn = false;
    const std::string filename = "user_details_cpp_dataset.csv";
    std::string* userDetailsArr = new std::string[4];

    if (IsUsernameUsed(testUserName)) {

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
        username  = userDetailsArr[j];
        j++;
        password = userDetailsArr[j];

        

        if(testUserName == username && testPassword == password){
            loggedIn = true;
            userID = stoi(userDetailsArr[0]);

        }
        delete[] userDetailsArr;
    }

    return loggedIn;
}

void User_details::logOut(){
    User_details();
}