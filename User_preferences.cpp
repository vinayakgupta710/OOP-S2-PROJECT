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
    movie1Score = 0;
    movie2Score = 0;
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

void User_preferences::printFavMovies(){
    const std::string filename = "user_details_cpp_dataset.csv";

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
    
    std::string favMovieList = userDetailsArr[3];
    delete[] userDetailsArr;

    std::string* favMovieArr;
    int len = 1;
    // finding the number of user's fav movies
    for(int i = 0; i < favMovieList.length(); i++){
        if(favMovieList[i] == ';'){
            len++;
        }
    }

    favMovieArr = new std::string[len];
    int j = 0;

    // building an array of fav movie titles
    std::string tempMovie = "";
    for(int i = 0; i < favMovieList.length(); i++){
        if(favMovieList[i] != ';'){
            tempMovie += favMovieList[i];
        } else {
            favMovieArr[j] = tempMovie;
            tempMovie = "";
            j++;
        }
    }
    favMovieArr[len - 1] = tempMovie;

    for(int i = 0; i < len; i++){
        std::string title = favMovieArr[i];
        favMovies.push_back(title);
    }

    // converting the first letter of all titles to capital
    for(int i = 0; i < len; i++){
        favMovieArr[i][0] = toupper(favMovieArr[i][0]);
    }

    // printing all the titles
    std::cout << "The list of " << username << "'s favourite movies includes: "; 
    for(int i = 0; i < len; i++){
        if(i < len - 1){
            std::cout << favMovieArr[i] << ", ";
        } else {
            std::cout << favMovieArr[i] << std::endl;
        }
    }

    delete[] favMovieArr;
}

void User_preferences::removeMovieFromFavourites(std::string title){
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

    userDetailedLine = userDetailsArr[3];
    std::stringstream userDetailedLineInParts(userDetailedLine);
    std::string separatedLine;
    int totalNumOfMovies = 0;
    int count = 0; // num of movies not matched with the parameter

    // checking if the title of the movie is in user's fav movie list
    while(std::getline(userDetailedLineInParts, separatedLine, ';')){
        std::string tempMovieName = separatedLine;
        totalNumOfMovies++;
        // changing the title of the movie to lowercase
        for(int i = 0; i < tempMovieName.length(); i++){
            tempMovieName[i] = tolower(tempMovieName[i]);
        }
        // changing the title parameter to lowercase
        for(int i = 0; i < title.length(); i++){
            title[i] = tolower(title[i]);
        }
    
        if(tempMovieName != title){
            count++;
        }
    }

    if(count == totalNumOfMovies){
        std::cout << "Movie does not exist in favourites!" << std::endl;
        return;
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

    std::stringstream tempUserDetailedLineInParts(userDetailsArr[3]);
    std::string tempSeparatedLine;
    std::string titleTemp = title;
    std::string newFavMovieList = "";
    // removing the title of the movie from user's fav list
    while(std::getline(tempUserDetailedLineInParts, tempSeparatedLine, ';')){
        std::string tempMovieName = tempSeparatedLine;

        // changing the title of the movie to lowercase
        for(int i = 0; i < tempMovieName.length(); i++){
            tempMovieName[i] = tolower(tempMovieName[i]);
        }
        // changing the title parameter to lowercase
        for(int i = 0; i < titleTemp.length(); i++){
            titleTemp[i] = tolower(titleTemp[i]);
        }
    
        if(tempMovieName != titleTemp){
            newFavMovieList += tempMovieName + ";";
        }
    }
    newFavMovieList.pop_back();// removing ; from the end of the line
    std::string newUserDetailsInStr = userDetailsInStr + "," + newFavMovieList;
    userDetailsInStr = userDetailsInStr +  "," + userDetailsArr[3];

    for(int i = 0; i < len; i++){
        if(tempArr[i] == userDetailsInStr){
            userDetailsInStr = newUserDetailsInStr;
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