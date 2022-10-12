#ifndef RATINGS_PREFERENCES
#define RATINGS_PREFERENCES

#include "Preferences.h"
#include "User_preferences.h"
#include <vector>

class Ratings_preferences: public Preferences, public virtual User_preferences{
private:
    std::vector<float> ratings; // vector of release years of the fav movies of the user
    float avgRatings; // average release year of the movies
    int ratingsScore;
public:
    Ratings_preferences(); // default constructor
    void updateUserPreference(std::string, std::string); // adds the release year vector and calculates the average
    void calculatePreferenceScore(std::string title); // calculates the preference score usign the algo
    int getScore(); // returns the release year score
};

#endif