import Pothos

"""/*
|PothosDoc Simple Python Adder

Add two input streams, produce an output stream.

|category /Math

|param dtype[Data Type] The input and output data type.
|default "float32"
|widget DTypeChooser(float=1,cfloat=1,int=1,cint=1,dim=1)
|preview disable

|factory /examples/simple_python_adder(dtype)
*/"""
class Adder(Pothos.Block):
    def __init__(self, dtype):
        Pothos.Block.__init__(self)
        self.setupInput(0, dtype)
        self.setupInput(1, dtype)
        self.setupOutput(0, dtype)

    def work(self):
        #how many elements to process?
        n = self.workInfo().minElements

        #grab the input and output ports
        inPort0 = self.input(0)
        inPort1 = self.input(1)
        outPort = self.output(0)

        #grab the input and output buffers
        in0 = inPort0.buffer()
        in1 = inPort1.buffer()
        out = outPort.buffer()

        #perform arithmetic
        out[:n] = in0[:n] + in1[:n]

        #produce and consume elements
        inPort0.consume(n)
        inPort1.consume(n)
        outPort.produce(n)
