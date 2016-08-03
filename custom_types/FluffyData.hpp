#pragma once
#include <Pothos/Config.hpp>
#include <string>

#ifdef FluffyData_EXPORTS
#define FluffyData_API POTHOS_HELPER_DLL_EXPORT
#else
#define FluffyData_API POTHOS_HELPER_DLL_IMPORT
#endif

//! FluffyData is a made up class to demonstrate type registration
class FluffyData_API FluffyData
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
