import sys
import time
import Pothos

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: tester.py /demos/fluffy_source /demos/fluffy_sink")
        exit(-1)
    sourcePath = sys.argv[1]
    sinkPath = sys.argv[2]

    #make topology and blocks
    t = Pothos.Topology()
    source = Pothos.BlockRegistry(sourcePath)
    sink = Pothos.BlockRegistry(sinkPath)
    t.connect(source, 0, sink, 0)

    print('#'*40)
    print('## Run for 1 second...')
    print('#'*40)

    #run for 1 second
    t.commit()
    time.sleep(1)

    #cleanup connections
    t.disconnectAll()
    t.commit()

    print('#'*40)
    print('## Done!')
    print('#'*40)
