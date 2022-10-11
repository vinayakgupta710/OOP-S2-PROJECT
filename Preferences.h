#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "User_preferences.h"

class Preferences{
public:
    virtual void updateUserPreference() = 0;
    virtual void calculatePreferenceScore(std::string title) = 0;
};

#endif