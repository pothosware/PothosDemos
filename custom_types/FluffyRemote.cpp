#include <Pothos/Init.hpp>
#include <Pothos/Proxy.hpp>
#include <Pothos/Remote.hpp>
#include "FluffyData.hpp" //use class definition in demo pt2
#include <iostream>
#include <cstdlib>

void demo(const std::string &uri)
{
    //connect to the remote server
    Pothos::RemoteClient client(uri);

    //create a proxy environment for C++ objects
    auto env = client.makeEnvironment("managed");

    //create a FluffyData
    auto FluffyDataCls = env->findProxy("FluffyData");
    auto remoteData = FluffyDataCls(123);
    remoteData.set("wiggles", "yippee");

    //print the data
    std::cout << "FluffyRemote: fluff=" << remoteData.call<int>("getFluff") << std::endl;
    std::cout << "FluffyRemote: wiggles=" << remoteData.get<std::string>("wiggles") << std::endl;

    //get a FluffyData locally
    auto localData = remoteData.convert<FluffyData>();
    std::cout << "FluffyLocal: fluff=" << localData.getFluff() << std::endl;
    std::cout << "FluffyLocal: wiggles=" << localData.wiggles << std::endl;

    //copy into a second remote object
    auto remoteData2 = env->makeProxy(localData);
    remoteData2.callVoid("setFluff", 987);
    std::cout << "FluffyRemote2: fluff=" << remoteData2.call<int>("getFluff") << std::endl;
    std::cout << "FluffyRemote2: wiggles=" << remoteData2.get<std::string>("wiggles") << std::endl;

    //get a FluffyData locally
    auto localEnv = Pothos::ProxyEnvironment::make("managed");
    auto localData2 = localEnv->makeProxy(remoteData2.toObject());
    std::cout << "FluffyLocal2: fluff=" << localData2.call<int>("getFluff") << std::endl;
    std::cout << "FluffyLocal2: wiggles=" << localData2.get<std::string>("wiggles") << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: FluffyRemote tcp://host:port" << std::endl;
        return EXIT_FAILURE;
    }

    //load the modules into the plugin tree
    Pothos::ScopedInit init;

    //run the demo
    try
    {
        demo(argv[1]);
    }
    catch (const Pothos::Exception &ex)
    {
        std::cout << ex.displayText() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
