# C++ JIT block demo

This directory is an example of a C++ JIT compilation unit.
Its composed of:

* SimpleFloatAdder.cpp - A simple C++ block with block description markup for the GUI
* SimpleFloatAdder.conf - a config file to describe the compilation unit

## Installing

Pothos will automatically take care of compiling the source when the block is instantiated.
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
ln -sf $(pwd) ${HOME}/.config/Pothos/modules/examples/simple_float_adder
```

## Option 2: copy

Copy this directory into system install prefix.
Use this option when installing processing IP permanently,
like from a larger build system or package manager.

```
cd pothos-demos/jit_cpp_block
mkdir -p /usr/local/share/Pothos/modules/examples
cp -r . /usr/local/share/Pothos/modules/examples/simple_float_adder
```
