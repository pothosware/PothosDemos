#include <Pothos/Framework.hpp>
#include "FluffyData.hpp" //use class definition in source version 1

class FluffySource1 : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new FluffySource1();
    }

    FluffySource1(void)
    {
        this->setupOutput(0);
    }

    void work(void)
    {
        auto outPort = this->output(0);

        //setup the data
        FluffyData data(1);
        data.wiggles = "Wiggle1";

        //produce the data as a message
        outPort->postMessage(data);
    }
};

static Pothos::BlockRegistry registerFluffySource1(
    "/demos/fluffy_source1", &FluffySource1::make);
