#ifndef RELEASE_YEAR_PREFERENCES
#define RELEASE_YEAR_PREFERENCES

#include "Preferences.h"
#include "User_preferences.h"
#include <vector>

class Release_year_preferences: public Preferences, public User_preferences{
private:
    std::vector<int> releaseYear; // vector of release years of the fav movies of the user
    float avgReleaseYear; // average release year of the movies
public:
    Release_year_preferences(); // default constructor
    void updateUserPreference(); // adds the release year vector and calculates the average
    void calculatePreferenceScore(); // calculates the preference score usign the algo
};

#endif