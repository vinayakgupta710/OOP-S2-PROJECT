#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "User_preferences.h"

class Preferences{
public:
    virtual void updateUserPreference(std::string username, std::string password) = 0;
    virtual void calculatePreferenceScore(std::string title) = 0;
    virtual int getScore() = 0;
};

#endif