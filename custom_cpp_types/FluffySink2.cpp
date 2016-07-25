#include <Pothos/Framework.hpp>
#include <Pothos/Proxy.hpp>
#include <iostream>

class FluffySink2 : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new FluffySink2();
    }

    FluffySink2(void):
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
        const auto data = _env->makeProxy(msg);

        //print the data
        std::cout << "FluffySink2: fluff=" << data.call<int>("getFluff") << std::endl;
        std::cout << "FluffySink2: wiggles=" << data.get<std::string>("wiggles") << std::endl;
    }

private:
    Pothos::ProxyEnvironment::Sptr _env;
};

static Pothos::BlockRegistry registerFluffySink2(
    "/demos/fluffy_sink2", &FluffySink2::make);
