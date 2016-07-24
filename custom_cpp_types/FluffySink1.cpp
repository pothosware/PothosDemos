#include <Pothos/Framework.hpp>
#include "FluffyData.hpp" //use class definition in sink version 1
#include <iostream>

class FluffySink1 : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new FluffySink1();
    }

    FluffySink1(void)
    {
        this->setupInput(0);
    }

    void work(void)
    {
        auto inPort = this->input(0);

        //do we have an input message?
        if (not inPort->hasMessage()) return;

        //extract the data
        const auto msg = inPort->popMessage();
        const auto &data = msg.extract<FluffyData>();

        //print the data
        std::cout << "FluffySink1: fluff=" << data.getFluff() << std::endl;
        std::cout << "FluffySink1: wiggles=" << data.wiggles << std::endl;
    }
};

static Pothos::BlockRegistry registerFluffySink1(
    "/demos/fluffy_sink1", &FluffySink1::make);
