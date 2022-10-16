#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "User_preferences.h"
#include "User_details.h"
#include "Movies_database.h"
#include "Preferences.h"
#include "Genre_preferences.h"

Genre_preferences::Genre_preferences(){
    genres.push_back("Action");
    genres.push_back("Adventure");
    genres.push_back("Animation");
    genres.push_back("Horror");
    genres.push_back("Comedy");
    genres.push_back("Crime");
    genres.push_back("Drama");
    genres.push_back("Fantasy");
    genres.push_back("Romance");
    genres.push_back("Thriller");
    genres.push_back("Mystery");
    genres.push_back("ScienceFiction");
    genres.push_back("Documentary");

    for(int i = 0; i < genres.size(); i++){
        genreOccurences.push_back(0);
    }

    genresScore = 0;
}

void Genre_preferences::updateUserPreference(std::string username, std::string password){
    genresScore = 0;
    Genre_preferences* tempGenre = new Genre_preferences;
    tempGenre->checkCredentials(username, password);

    Movies_database** favMovieList = new Movies_database*[favMovies.size()];
    for(int i = 0; i < favMovies.size(); i++){
        favMovieList[i] = new Movies_database;
    }

    for(int i = 0; i < favMovies.size(); i++){
        Movies_database tempMovie;
        std::string title = favMovies.at(i);
        favMovieList[i] = tempMovie.fetchMovie(title);
    }

    for(int i = 0; i < favMovies.size(); i++){
        int lenOfTempGenre = favMovieList[i]->getNumOfGenres();
        std::string* tempGenres = favMovieList[i]->getGenreList();

        for(int j = 0; j < lenOfTempGenre; j++){
            for(int k = 0; k < genres.size(); k++){
                if(tempGenres[j] == genres.at(k)){
                    genreOccurences.at(k) += 1;
                }
            }
        }
    }

    delete[] favMovieList;
}

void Genre_preferences::calculatePreferenceScore(std::string title){
    Movies_database* movie_object = new Movies_database;

    movie_object = movie_object->fetchMovie(title);
    std::string* genreArr = movie_object->getGenreList();
    int len = movie_object->getNumOfGenres();

    for(int i = 0; i < genres.size(); i++){
        for(int j = 0; j < len; j++){
            if(genreArr[j] == genres.at(i)){
                std::cout << genreArr[j] << " " << genres.at(i) << std::endl;
                genresScore += genreOccurences.at(i);
                break;
            }
        }
    }
    delete movie_object;

    genresScore += (genresScore/2);
}

int Genre_preferences::getScore(){ return genresScore; }