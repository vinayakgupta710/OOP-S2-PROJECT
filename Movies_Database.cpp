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

// adding a movie to the database (csv file)
bool Movies_database::addMovie(){
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

    // getting the release year of the movie from the user
    std::cout << "Enter the release year for " << title << ": ";
    std::cin >> year;

    // getting the genres of the movie from the user
    std::cout << "How many genres do you wish to add for " << title << ": ";
    std::cin >> numOfGenres;
    genres = new std::string[numOfGenres];

    for(int i = 0; i < numOfGenres; i++){
        std::string tempGenre = "";
        
        std::cout << "Enter the genre of " << title << ": ";
        std::cin >> tempGenre;

        genres[i] = tempGenre;
    }

    // getting the production studio of the movie from the user
    std::cin.ignore();
    std::cout << "Enter the studio that produced " << title << ": ";
    getline(std::cin, studio);

    // getting the rating of the movie from the user
    std::cout << "Enter the rating for " << title << ": ";
    std::cin >> rating;

    // HAVE TO GET THE LAST LINE OF THE CSV FILE AND SET THE ID TO + 1

    // HAVE TO ADD IT IN THE CSV FILE

    return true;
}

