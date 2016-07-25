#include <Pothos/Framework.hpp>
#include <Pothos/Proxy.hpp>

class FluffySource2 : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new FluffySource2();
    }

    FluffySource2(void):
        _env(Pothos::ProxyEnvironment::make("managed"))
    {
        this->setupOutput(0);
    }

    void work(void)
    {
        auto outPort = this->output(0);

        //setup the data
        auto FluffyDataClass = _env->findProxy("FluffyData");
        auto data = FluffyDataClass(2);
        data.set("wiggles", "Wiggle2");

        //produce the data as a message
        outPort->postMessage(_env->convertProxyToObject(data));
    }

private:
    Pothos::ProxyEnvironment::Sptr _env;
};

static Pothos::BlockRegistry registerFluffySource2(
    "/demos/fluffy_source2", &FluffySource2::make);
