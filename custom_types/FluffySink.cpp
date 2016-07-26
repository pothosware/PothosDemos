#include <Pothos/Framework.hpp>
#include "FluffyData.hpp" //use class definition in sink version 1
#include <iostream>

class FluffySink : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new FluffySink();
    }

    FluffySink(void)
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
        std::cout << "FluffySink: fluff=" << data.getFluff() << std::endl;
        std::cout << "FluffySink: wiggles=" << data.wiggles << std::endl;
    }
};

static Pothos::BlockRegistry registerFluffySink(
    "/demos/fluffy_sink", &FluffySink::make);
