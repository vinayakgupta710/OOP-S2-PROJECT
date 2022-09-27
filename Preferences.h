#ifndef PREFERENCES_H
#define PREFERENCES_H

class Prefernces{
public:
    virtual void updateUserPreference() = 0;
    virtual void calculatePreferenceScore() = 0;
};

#endif