#include "FluffyData.hpp"

/***********************************************************************
 * FluffyData class implementation
 **********************************************************************/
FluffyData::FluffyData(void):
    _fluff(0)
{
    return;
}

FluffyData::FluffyData(const int fluff):
    _fluff(fluff)
{
    return;
}

void FluffyData::setFluff(const int fluff)
{
    _fluff = fluff;
}

int FluffyData::getFluff(void) const
{
    return _fluff;
}

/***********************************************************************
 * FluffyData class registration
 * Doing this lets us interact with FluffyData through Pothos::Proxy
 * which also includes network use and Python language integration.
 **********************************************************************/
#include <Pothos/Managed.hpp>

static auto managedFluffyData = Pothos::ManagedClass()
    .registerConstructor<FluffyData>()
    .registerConstructor<FluffyData, int>()
    .registerMethod(POTHOS_FCN_TUPLE(FluffyData, getFluff))
    .registerMethod(POTHOS_FCN_TUPLE(FluffyData, setFluff))
    .registerField(POTHOS_FCN_TUPLE(FluffyData, wiggles))
    .commit("FluffyData");

/***********************************************************************
 * FluffyData class serialization
 * Serialization hooks allow FluffyData to be passed over a socket.
 **********************************************************************/
#include <Pothos/Object/Serialize.hpp>
#include <iostream>

namespace Pothos { namespace serialization {
template <class Archive>
void save(Archive & ar, const FluffyData &t, const unsigned int)
{
    std::cout << "save FluffyData" << std::endl;
    const int fluff(t.getFluff());
    ar << fluff;
    ar << t.wiggles;
}

template <class Archive>
void load(Archive & ar, FluffyData &t, const unsigned int)
{
    std::cout << "load FluffyData" << std::endl;
    int fluff(0);
    ar >> fluff;
    t = FluffyData(fluff);
    ar >> t.wiggles;
}

template <class Archive>
void serialize(Archive & ar, FluffyData &t, const unsigned int version)
{
    Pothos::serialization::split_free(ar, t, version);
}
}}

POTHOS_OBJECT_SERIALIZE(FluffyData)
