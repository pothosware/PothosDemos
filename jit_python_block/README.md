# Python JIT block demo

This directory demonstrates how to install a Python block
without compiling any loadable wrapper code.
Prior to this feature, making a block in Python
required a CMake project and some minor compiling + installing.
This project is composed of:

* SimpleAdder.py - A simple Python adder with block description markup for the GUI
* SimpleAdder.conf - a config file to describe the python modules and factory paths

## Installing

Pothos will automatically take care of extracting the block descriptions
and dynamically creating factories that call into python.
These factories import  the python module and instantiate the block.
We only need to make Pothos aware of this compilation unit with configuration file.
To do this we either need to copy this directory to a known location
or to symlink this directory to a well known location.

## Option 1: symlink

Symlink this directory into the user's home directory.
Use this option when the source is being developed and maintained
in a source code repository. Pothos will automatically rebuild
on plugin reload if the local source in the repository is changed.

```
cd pothos-demos/jit_cpp_block
mkdir -p ${HOME}/.config/Pothos/modules/examples
ln -sf $(pwd) ${HOME}/.config/Pothos/modules/examples/simple_python_adder
```

## Option 2: copy

Copy this directory into system install prefix.
Use this option when installing processing IP permanently,
like from a larger build system or package manager.

```
cd pothos-demos/jit_cpp_block
mkdir -p /usr/local/share/Pothos/modules/examples
cp -r . /usr/local/share/Pothos/modules/examples/simple_python_adder
```

## Running

An demonstration topology ``topology_python_adder.pothos`` is included
along with the python adder block. Simply open this topology
in the Pothos GUI and the block will be automatically available.
