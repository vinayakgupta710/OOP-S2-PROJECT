#ifndef STUDIO_PREFERENCES
#define STUDIO_PREFERENCES

#include "Preferences.h"
#include "User_preferences.h"
#include <vector>

class Studio_preferences: public Preferences, public User_preferences{
private:
    std::vector<std::string> studios; // vector of release years of the fav movies of the user
    int studioScore;
public:
    Studio_preferences(); // default constructor
    void updateUserPreference(); // adds the release year vector and calculates the average
    void calculatePreferenceScore(std::string title); // calculates the preference score usign the algo
    int getScore(); // returns the release year score
};

#endif