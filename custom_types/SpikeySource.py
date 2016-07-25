import Pothos
from SpikeyData import SpikeyData

class SpikeySource(Pothos.Block):
    def __init__(self):
        Pothos.Block.__init__(self)
        self.setupOutput(0)

    def work(self):
        outPort = self.output(0)

        #setup the data
        data = SpikeyData(4)
        data.ouch = "Ouch4"

        #produce the data as a message
        outPort.postMessage(data)
