#ifndef RELEASE_YEAR_PREFERENCES
#define RELEASE_YEAR_PREFERENCES

#include <vector>

#include "Preferences.h"
#include "User_preferences.h"

class Release_year_preferences : public Preferences,
                                 public virtual User_preferences {
 private:
  std::vector<int>
      releaseYear;  // vector of release years of the fav movies of the user
  float avgReleaseYear;  // average release year of the movies
  int releaseYearScore;

 public:
  Release_year_preferences();  // default constructor
  void updateUserPreference(
      std::string,
      std::string);  // adds the release year vector and calculates the average
  void calculatePreferenceScore(
      std::string title);  // calculates the preference score usign the algo
  int getScore();          // returns the release year score
};

#endif