#include <Pothos/Framework.hpp>
#include <Pothos/Proxy.hpp>

class SpikeySource : public Pothos::Block
{
public:
    static Block *make(void)
    {
        return new SpikeySource();
    }

    SpikeySource(void):
        _env(Pothos::ProxyEnvironment::make("python"))
    {
        this->setupOutput(0);
    }

    void work(void)
    {
        auto outPort = this->output(0);

        //setup the data
        auto DemoModule = _env->findProxy("PothosDemosCustomTypes");
        auto SpikeyData = DemoModule.get("SpikeyData");
        auto data = SpikeyData(4);
        data.set("ouch", "Ouch4");

        //produce the data as a message
        outPort->postMessage(data);
    }

private:
    Pothos::ProxyEnvironment::Sptr _env;
};

static Pothos::BlockRegistry registerSpikeySource(
    "/demos/spikey_source", &SpikeySource::make);
