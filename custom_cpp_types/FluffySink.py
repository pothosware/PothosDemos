import Pothos

class FluffySink(Pothos.Block):
    def __init__(self):
        Pothos.Block.__init__(self)
        self.setupInput(0)

    def work(self):
        inPort = self.input(0)

        #do we have an input message?
        if not inPort.hasMessage(): return

        #extract the data
        data = inPort.popMessage()

        #print the data
        print("FluffySink2: fluff=%d"%data.getFluff())
        print("FluffySink2: wiggles=%s"%data.wiggles)
