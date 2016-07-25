class SpikeyData:
    def __init__(self, spike=0):
        self._spike = spike
        self._ouch = "Ouch!"

    def getSpike(self):
        return self._spike

    def setSpike(self, spike):
        self._spike = spike
