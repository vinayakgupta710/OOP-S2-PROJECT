#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movies_database.h"

// default constructor sets everything to 0/null
Movies_database::Movies_database(){
    movieID = 0;
    titleOfMovie = "no title";
    releaseYear = 0;
    genreOfMovie = NULL;
    studioOfMovie = "no studio";
    ratingOfMovie = 0.0;
}

// parametric constructor to change the values of private data members
Movies_database::Movies_database(std::string title, int year, std::string* genres, std::string studio, float ratings, int id){
    titleOfMovie = title;
    releaseYear = year;
    genreOfMovie = genres;
    studioOfMovie = studio;
    ratingOfMovie = ratings;
    movieID = id;
}

// checking if a movie is in a database
bool Movies_database::isMovieInDatabase(std::string title){

    // capitalising the first letter of every word of the movie
    title[0] = toupper(title[0]);
    for(int i = 1; i < title.length(); i++){
        if(title[i - 1] == ' '){
            title[i] = toupper(title[i]);
        } else {
            title[i] = tolower(title[i]);
        }
    }

    // setting the bool value to false by default
    bool inDatabase = false;
    const std::string filename = "final_cpp_dataset.csv";

    // readinf the csv file
    std::ifstream movieDatabase(filename);
    // reading the file line by line and changing the bool value to true if the movie exists in the database
    for(std::string line; getline(movieDatabase, line); ){
        // using find() function to check if the title is present in the row of the csv
        if(line.find(title) != std::string::npos){
            inDatabase = true;
        }
    }

    return inDatabase;
}

// adding a movie to the database (csv file)
bool Movies_database::addMovie(){
    const std::string filename = "final_cpp_dataset.csv";
    
    int id = 0; 
    std::string title = ""; 
    int year = 0; 
    int numOfGenres = 0;
    std::string* genres; 
    std::string studio = ""; 
    float rating = 0; 

    // getting the title of the movie from the user
    std::cout << "Enter the title of the movie you wish to add to the database: "; 
    getline(std::cin, title);

    // if movie exists in database throw error
    if(isMovieInDatabase(title)){
        std::cout << "Error! Movie already in database!" << std::endl;

        // change this so that the program does not quit
        return false;
    }

    // getting the release year of the movie from the user
    std::cout << "Enter the release year for " << title << ": ";
    std::cin >> year;
    while(year <= 1920 || year > 2023){
        std::cout << "Error! Invalid year!" << std::endl;
        std::cout << "Try again!" << std::endl;
        std::cout << "Enter the release year for " << title << ": ";
        std::cin >> year;
    }

    // getting the genres of the movie from the user
    std::cout << "How many genres do you wish to add for " << title << ": ";
    std::cin >> numOfGenres;
    // checking if the number of genres is invalid
    while(numOfGenres <= 0 || numOfGenres > 18){
        std::cout << "Error! Invalid number of genres!" << std::endl;
        std::cout << "Try again!" << std::endl;
        std::cout << "How many genres do you wish to add for " << title << ": ";
        std::cin >> numOfGenres;
    }
    genres = new std::string[numOfGenres];

    for(int i = 0; i < numOfGenres; i++){
        std::string tempGenre = "";
        std::cout << "Enter the genre of " << title << ": ";
        std::cin >> tempGenre;
        genres[i] = tempGenre;
    }

    std::string genreForMovie;
    genreForMovie = "[";
    for(int i = 0; i < numOfGenres - 1; i++){
        genreForMovie = genreForMovie + genres[i] + ", ";
    }
    genreForMovie = genreForMovie + genres[numOfGenres - 1] + "]";
    delete[] genres;

    // getting the production studio of the movie from the user
    std::cin.ignore();
    std::cout << "Enter the studio that produced " << title << ": ";
    getline(std::cin, studio);

    // getting the rating of the movie from the user
    std::cout << "Enter the rating for " << title << ": ";
    std::cin >> rating;
    // checking if the number of genres is invalid
    while(rating <= 0 || rating > 10){
        std::cout << "Error! Invalid rating!" << std::endl;
        std::cout << "Allowed range: 1 to 10." << std::endl;
        std::cout << "Try again!" << std::endl;
         std::cout << "Enter the rating for " << title << ": ";
        std::cin >> rating;
    }

    // extracting the id from the database and settng the new entry to id+1
    std::ifstream movieDatabaseTemp(filename);
    std::string tempLine;
    while(getline(movieDatabaseTemp, tempLine)){}
    // finding the first word from the tempLine
    std::string movieIdInStr;
    int commaIndexInMovie = 0;
    for(int i = 0; i < tempLine.length(); i++){
        if(tempLine[i] == ','){
            commaIndexInMovie = i;
            break;
        }
    }
    for(int i = 0; i < commaIndexInMovie; i++){
        movieIdInStr = movieIdInStr + tempLine[i];
    }
    id = stoi(movieIdInStr);
    id = id + 1;

    // HAVE TO ADD IT IN THE CSV FILE
    std::ofstream movieDatabaseOut(filename, std::ios::app);
    movieDatabaseOut << std::to_string(id) + "," + genreForMovie + "," + "en," + title + "," + std::to_string(year) + "," + std::to_string(rating) + "," + studio + ",/n";
    movieDatabaseOut.close();
    return true;
}

