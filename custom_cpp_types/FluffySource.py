import Pothos

class FluffySource(Pothos.Block):
    def __init__(self):
        Pothos.Block.__init__(self)
        self.setupOutput(0)

    def work(self):
        
