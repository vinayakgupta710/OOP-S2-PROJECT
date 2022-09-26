#ifndef MOVIES_DATABASE_H
#define MOVIES_DATABASE_H

#include <string>

class Movies_database{
private:
    int movieID; // unique ID for each movie
    std::string titleOfMovie; // Title of the movie
    int releaseYear; // release year of the movie
    int numOfGenres; // num of genres of the movie
    std::string* genreOfMovie; // array of genres of the movie
    std::string studioOfMovie; // production studio of the movie
    float ratingOfMovie; // avg rating of the movie as per themoviedb.org
public:
    // Default constructor 
    Movies_database(); 
    // Used as a setter function in the fetch details function of the Movies_Database class
    Movies_database(std::string title, int lenOfGenre, int year, std::string* genres, std::string studio, float ratings, int id);
    // sets the details of the movie
    void setDetails(std::string title, int lenOfGenre, int year, std::string* genres, std::string studio, float ratings, int id);
    //Adds a movie to the database and returns true if its successful
    bool addMovie();
    // checks if the title of the movie is a valid title in the database
    bool isMovieInDatabase(std::string title);
    // checks if the ID of the movie is a valid ID in the database
    bool isMovieInDatabase(int ID);
    // fetches the details of the movie existing in the database and returns new Movies_Database object
    // would be a instantiated on the heap
    Movies_database* fetchMovie(std::string title);
    // getter Functions
    int getId();
    std::string getTitle(); 
    int getReleaseYear(); 
    int getNumOfGenres(); 
    std::string* getGenreList(); 
    std::string getStudio(); 
    float getRating(); 
};

#endif