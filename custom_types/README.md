# Custom C++ Type demo

A family of blocks may employ the use of custom data types as messages.
This demonstration shows how type registration and type serialization
can be used with a custom data type to cross process and language boundaries.

Consider the custom type FluffyData. Using several variants of a simple
source and sink block, we can demonstrate how a registered type
can be interacted with using the Pothos::Proxy abstraction.

* FluffySource1 - produces FluffySource with the class definition
* FluffySource2 - produces FluffySource with the class registration
* FluffySink1 - consumes and prints FluffySource with the class definition
* FluffySink2 - consumes and prints FluffySource with the class registration
* PyFluffySource - produces FluffySource in python
* PyFluffySink - consumes and prints FluffySource in python
