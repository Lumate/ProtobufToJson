ProtobufToJson
==============
simple library for serializing protobufs to json strings

Installation
```
git clone --recursive git@github.com:Lumate/ProtobufToJson.git
cd ProtobufToJson
mkdir build
cd build
cmake ..
make
```

Usage
```
#include example.pb.cc
#include <iostream>
int main() {
    static const std::map<std::string, std::string> FIELDS = { {"device_id", "did"}};
    Example example;
    std::cout << serializeAsString(example, FIELDS) << std::endl;
    return 0;
}
```
