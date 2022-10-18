#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "User_preferences.h"

class Preferences {
 public:
  // updates the preferences of the user
  virtual void updateUserPreference(std::string username, std::string password) = 0;
    // calculates the score
  virtual void calculatePreferenceScore(std::string title) = 0;
  // gets the score
  virtual int getScore() = 0;
};

#endif