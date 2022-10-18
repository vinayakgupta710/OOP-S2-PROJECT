#ifndef STUDIO_PREFERENCES
#define STUDIO_PREFERENCES

#include <vector>

#include "Preferences.h"
#include "User_preferences.h"

class Studio_preferences : public Preferences, public virtual User_preferences {
 private:
  std::vector<std::string>
      studios;  // vector of release years of the fav movies of the user
  int studioScore;

 public:
  Studio_preferences();  // default constructor
  void updateUserPreference(
      std::string,
      std::string);  // adds the release year vector and calculates the average
  void calculatePreferenceScore(
      std::string title);  // calculates the preference score usign the algo
  int getScore();          // returns the release year score
};

#endif