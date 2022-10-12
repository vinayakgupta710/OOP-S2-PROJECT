#ifndef GENRE_PREFERENCES
#define GENRE_PREFERENCES

#include "Preferences.h"
#include "User_preferences.h"
#include <vector>

class Genre_preferences: public Preferences, public virtual User_preferences{
private:
    std::vector<std::string> genres; // vector of release years of the fav movies of the user
    std::vector<int> genreOccurences; // num of genre occurences
    int genresScore;
public:
    Genre_preferences(); // default constructor
    void updateUserPreference(std::string, std::string); // adds the release year vector and calculates the average
    void calculatePreferenceScore(std::string title); // calculates the preference score usign the algo
    int getScore(); // returns the release year score
};

#endif