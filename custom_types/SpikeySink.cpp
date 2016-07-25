#include <Pothos/Framework.hpp>
#include <Pothos/Proxy.hpp>
#include <iostream>

class SpikeySink : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new SpikeySink();
    }

    SpikeySink(void):
        _env(Pothos::ProxyEnvironment::make("managed"))
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
        const auto &data = msg.extract<Pothos::Proxy>();

        //print the data
        std::cout << "SpikeySink: spike=" << data.call<int>("getSpike") << std::endl;
        std::cout << "SpikeySink: ouch=" << data.get<std::string>("ouch") << std::endl;
    }

private:
    Pothos::ProxyEnvironment::Sptr _env;
};

static Pothos::BlockRegistry registerSpikeySink(
    "/demos/spikey_sink", &SpikeySink::make);
