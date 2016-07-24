import Pothos

class FluffySource(Pothos.Block):
    def __init__(self):
        Pothos.Block.__init__(self)
        self._env = Pothos.ProxyEnvironment("managed")
        self.setupOutput(0)

    def work(self):
        outPort = self.output(0)

        #setup the data
        FluffyDataClass = self._env.findProxy("FluffyData")
        data = FluffyDataClass.new(3)
        data.wiggles = "Wiggle3"

        #produce the data as a message
        outPort.postMessage(data)
