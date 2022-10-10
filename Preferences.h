#ifndef PREFERENCES_H
#define PREFERENCES_H

class Preferences: public User_preferences{
public:
    virtual void updateUserPreference() = 0;
    virtual void calculatePreferenceScore() = 0;
};

#endif