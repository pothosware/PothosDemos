#!/bin/bash

dir=${HOME}/.config/Pothos/modules/examples/simple_float_adder
#dir=/user/local/Pothos/modules/examples/simple_float_adder
echo "copying files to ${dir}"
mkdir -p ${dir}
cp SimpleFloatAdder.* ${dir}/
echo "done!"
