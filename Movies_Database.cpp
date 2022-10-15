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
    numOfGenres = 0;
    genreOfMovie = NULL;
    studioOfMovie = "no studio";
    ratingOfMovie = 0.0;
}

// parametric constructor to change the values of private data members
Movies_database::Movies_database(std::string title, int lenOfGenre, int year, std::string* genres, std::string studio, float ratings, int id){
    titleOfMovie = title;
    releaseYear = year;
    numOfGenres = lenOfGenre;
    genreOfMovie = genres;
    studioOfMovie = studio;
    ratingOfMovie = ratings;
    movieID = id;
}

void Movies_database::setDetails(std::string title, int lenOfGenre, int year, std::string* genres, std::string studio, float ratings, int id){
    titleOfMovie = title;
    releaseYear = year;
    numOfGenres = lenOfGenre;
    genreOfMovie = genres;
    studioOfMovie = studio;
    ratingOfMovie = ratings;
    movieID = id;
}

int Movies_database::getId() { return movieID; } 
std::string Movies_database::getTitle() { return titleOfMovie; } 
int Movies_database::getReleaseYear() { return releaseYear; } 
int Movies_database::getNumOfGenres() {return numOfGenres; } 
std::string* Movies_database::getGenreList() { return genreOfMovie; } 
std::string  Movies_database::getStudio() { return studioOfMovie; } 
float  Movies_database::getRating() {return ratingOfMovie; } 

// checking if a movie is in a database
bool Movies_database::isMovieInDatabase(std::string title){

    // capitalising the first letter of every word of the movie
    title[0] = toupper(title[0]);
    for(int i = 1; i < title.length(); i++){
        if(title[i - 1] == ' ' || title[i - 1] == '-' || title[i - 1] == ':'){
            title[i] = toupper(title[i]);
        } else {
            title[i] = tolower(title[i]);
        }
    }

    // setting the bool value to false by default
    bool inDatabase = false;
    const std::string filename = "final_cpp_dataset.csv";

    // reading the csv file
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
    bool addedMovies = true;
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
        addedMovies = false;
        return addedMovies;
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
        genreForMovie = genreForMovie + genres[i] + "; ";
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
    while(rating < 0 || rating > 10){
        std::cout << "Error! Invalid rating!" << std::endl;
        std::cout << "Allowed range: 0 to 10." << std::endl;
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

    std::ofstream movieDatabaseOut;
    movieDatabaseOut.open(filename, std::ios::app);

    movieDatabaseOut << "\n" << std::to_string(id) + "," + genreForMovie + "," + "en," + title + "," + std::to_string(year) + "," + std::to_string(rating) + "," + studio;
    movieDatabaseOut.close();
    return addedMovies;
}

// checking if a movie is in a database
bool Movies_database::isMovieInDatabase(int id){
    // setting the bool value to false by default
    bool inDatabase = false;
    const std::string filename = "final_cpp_dataset.csv";

    // reading the csv file
    std::ifstream movieDatabase(filename);
    // reading the file line by line and changing the bool value to true if the movie exists in the database
    for(std::string line; getline(movieDatabase, line); ){
        // using find() function to check if the title is present in the row of the csv
        if(line.find(id) != std::string::npos){
            inDatabase = true;
        }
    }

    return inDatabase;
}

Movies_database* Movies_database::fetchMovie(std::string title){
    const std::string filename = "final_cpp_dataset.csv";
    Movies_database* movieDetails = new Movies_database;
    // if movie is not in database, give the option to add it or search for new movie
    if(!isMovieInDatabase(title)){
        std::cout << "Movie does not exist in the database." << std::endl;
        std::cout << "Do you wish to add it in the database or would like to find another movie?" << std::endl;
        std::cout << "Type 'y' if you want to add it or 'n' if you would like to find another movie: ";
        std::string userTempInput;
        char addMovieOrContinue;
        std::cin >> userTempInput;
        addMovieOrContinue = userTempInput[0];
        
        while(addMovieOrContinue != 'y' || addMovieOrContinue != 'n'){
            std::cin.ignore();
            std::cout << "Only y or n character is allowed: ";
            std::cin >> userTempInput;
            addMovieOrContinue = userTempInput[0];
        }

        if(addMovieOrContinue == 'y'){
            std::cin.ignore();
            addMovie();
        } else {
            std::string newTitle;
            std::cout << "Enter the new title of the movie that you want to fetch information of: ";
            std::cin.ignore();
            getline(std::cin, newTitle);
            fetchMovie(newTitle);
        }
    }

    // if movie is in database make a new Movie object and store its information
    // capitalising the first letter of every word of the movie
    title[0] = toupper(title[0]);
    for(int i = 1; i < title.length(); i++){
        if(title[i - 1] == ' '){
            title[i] = toupper(title[i]);
        } else {
            title[i] = tolower(title[i]);
        }
    }

    // reading the csv file
    std::ifstream movieDatabase(filename);
    // reading the file line by line and changing the bool value to true if the movie exists in the database
    for(std::string line; getline(movieDatabase, line); ){
        // using find() function to check if the title is present in the row of the csv
        if(line.find(title) != std::string::npos){
            // creating a temp stringstream to find the desired len of the movie details arr
            std::stringstream rowContentMovieTemp(line);
            std::string separatedLineTemp;
            int lenOfMovieDetailsArr = 0;
            // creating a new array of movie details and then converting it into movie object
            while(std::getline(rowContentMovieTemp, separatedLineTemp, ',')){
                lenOfMovieDetailsArr++;
            }

            std::stringstream rowContentMovie(line);
            std::string separatedLine;
            std::string* movieDetailsArr; // dynamic string arrs
            movieDetailsArr = new std::string[lenOfMovieDetailsArr];
            int i = 0; // iterator for the arr
            while(std::getline(rowContentMovie, separatedLine, ',')){
                movieDetailsArr[i] = separatedLine;
                i++;
            }

            // id for the new movie Object
            int tempId = stoi(movieDetailsArr[0]);

            // genres arr for movies details
            std::string* tempGenre;
            int j = 1; // iterator for the creating a genres arr
            int lenForTempGenre = 1; // length of temp genre
            while(movieDetailsArr[lenForTempGenre] != "en"){
                lenForTempGenre++;
            }
            lenForTempGenre = lenForTempGenre - 1; // removing the 1 as it was initialised as 1 instead of 0
            tempGenre = new std::string[lenForTempGenre]; // creating a dynamic array of genres
            int iteratorForTempGenre = 0;
            while(movieDetailsArr[j] != "en"){

                std::string genre = "";
                for(int i = 0; i < movieDetailsArr[j].length(); i++){
                    if(movieDetailsArr[j][i] != '[' && movieDetailsArr[j][i] != ']' && movieDetailsArr[j][i] != ' ' && movieDetailsArr[j][i] != '"' && movieDetailsArr[j][i] != '\'' && movieDetailsArr[j][i] != ';'){
                        genre = genre + movieDetailsArr[j][i];
                    }
                }
                if(iteratorForTempGenre < lenForTempGenre){
                    tempGenre[iteratorForTempGenre] = genre;
                    iteratorForTempGenre++;
                }
                j++;
            }

            //adding the title of the movie to temp title
            j = j + 1;
            std::string titleTemp = movieDetailsArr[j];
                
            // adding the release year to temp year
            j = j + 1;
            int yearTemp = stoi(movieDetailsArr[j]);

            // adding the rating of the movie to tempRating
            j = j + 1;
            float ratingTemp = stof(movieDetailsArr[j]);

            // adding the studio to temp studio
            j = j + 1;
            std::string studioTemp = movieDetailsArr[j];

            // deleting moviesDetailsArr
            delete[] movieDetailsArr;

            // creating a dynamic Movies object
            movieDetails->setDetails(titleTemp, lenForTempGenre, yearTemp, tempGenre, studioTemp, ratingTemp, tempId);
            
        }
    }
    movieDatabase.close();
    return movieDetails;
}