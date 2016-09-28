#include <Pothos/Framework.hpp>

/***********************************************************************
 * |PothosDoc Simple Float Adder
 *
 * Add two floating point input streams and produce an output stream.
 *
 * This is an incredibly simple block.
 * Its main purpose is to demonstrate JIT compilation of C++ blocks.
 *
 * |category /Examples
 * |keywords math examples adder
 *
 * |factory /examples/simple_float_adder()
 **********************************************************************/
class SimpleFloatAdder : public Pothos::Block
{
public:
    SimpleFloatAdder(void)
    {
        this->setupInput(0, typeid(float));
        this->setupInput(1, typeid(float));
        this->setupOutput(0, typeid(float));
    }

    static Block *make(void)
    {
        return new SimpleFloatAdder();
    }

    void work(void)
    {
        //get the minimum number of elements available across all indexed ports
        const size_t N = this->workInfo().minElements;
        if (N == 0) return;

        //get pointers to the input and output ports and buffers
        auto inPort0 = this->input(0);
        auto inPort1 = this->input(1);
        auto outPort = this->output(0);
        const auto &inBuff0 = inPort0->buffer().as<const float *>();
        const auto &inBuff1 = inPort1->buffer().as<const float *>();
        const auto &outBuff = outPort->buffer().as<float *>();

        //perform the addition operation
        for (size_t i = 0; i < N; i++)
        {
            outBuff[i] = inBuff0[i] + inBuff1[i];
        }

        //produce and consume on all ports
        inPort0->consume(N);
        inPort1->consume(N);
        outPort->produce(N);
    }
};

//register SimpleFloatAdder into the block registry
static Pothos::BlockRegistry registerSimpleFloatAdder(
    "/examples/simple_float_adder", &SimpleFloatAdder::make);
