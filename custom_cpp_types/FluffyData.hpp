#pragma once
#include <string>

//! FluffyData is a made up class to demonstrate type registration
class FluffyData
{
public:

    //! Empty constructor
    FluffyData(void);

    //! Constructor with parameter
    FluffyData(const int fluff);

    //! A setter
    void setFluff(const int fluff);

    //! A getter
    int getFluff(void) const;

    //! A field
    std::string wiggles;

private:
    int _fluff;
};
