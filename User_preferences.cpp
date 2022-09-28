#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"

User_preferences::User_preferences(){
    genrePref = NULL;
    ratingPref = NULL;
    releaseYearPref = NULL;
    studioPref = NULL;
    favMovies = NULL;
}

void User_preferences::addMovieToFav(std::string title){
    std::string existingFavMovies;
    std::string userDetailedLine;
    const std::string filename = "user_details_cpp_dataset.csv";
    std::string titleCopy = title;

    // opening the file stream for userDatabase
    std::ifstream userDatabase(filename);
    std::string* userDetailsArr = new std::string[4];

    // reading the file line by line and extracting the username which matches the arg
    for(std::string line; getline(userDatabase, line); ){
        // using find() function to check if the username is present in the row of the csv
        if(line.find(username) != std::string::npos){
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
    userDatabase.close();
        
    std::stringstream userDetailedLineInParts(userDetailedLine);
    std::string separatedLine;
    
    while(std::getline(userDetailedLineInParts, separatedLine, ';')){
        std::string tempMovieName = separatedLine;
        
        for(int i = 0; i < tempMovieName.length(); i++){
            tempMovieName[i] = tolower(tempMovieName[i]);
        }

        for(int i = 0; i < title.length(); i++){
            title[i] = tolower(title[i]);
        }
        
        if(tempMovieName == title){
            std::cout << "Movie already exists in favourites!" << std::endl;
            return;
        }
    }

    std::ifstream userDatabaseIn;
    userDatabaseIn.open(filename);
    int len = 0;
    // getting the length of the total file
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
    len = stoi(userIdInStr);
    len += 2;
    movieDatabaseTemp.close();

    std::string *tempArr = new std::string[len];
    int i = 0; 
    for(std::string line; getline(userDatabaseIn, line); ){
        if(i < len){
            tempArr[i] = line;
            i++;
        }
    }

    std::string userDetailsInStr = userDetailsArr[0];

    for(int i = 1; i < 3; i++){
        userDetailsInStr = userDetailsInStr + "," + userDetailsArr[i];
    }
    userDetailsInStr = userDetailsInStr +  "," + userDetailsArr[3];
    userDetailsArr[3] = userDetailedLine;
    
    for(int i = 0; i < len; i++){
        if(tempArr[i] == userDetailsInStr){
            userDetailsInStr = userDetailsInStr + ";" + titleCopy;
            tempArr[i] = userDetailsInStr;
        }
    }
    delete[] userDetailsArr;

    int lenOfFilename = filename.length();
    char* TempFilename = new char[lenOfFilename];
    for(int i = 0; i < lenOfFilename; i++){
        TempFilename[i] = filename[i];
    }
    
    char newTempFilename[lenOfFilename];
    for(int i = 0; i <lenOfFilename; i++){
        newTempFilename[i] = TempFilename[i];
    }
    delete[] TempFilename;

    int status = remove(newTempFilename);

    std::ofstream userDatabaseOut;
    userDatabaseOut.open(filename, std::ios::app);
    userDatabaseOut << tempArr[0];
    for(int i = 1; i < len; i++){
        userDatabaseOut << "\n" << tempArr[i]; 
    }
    delete[] tempArr;
    userDatabaseOut.close();
}