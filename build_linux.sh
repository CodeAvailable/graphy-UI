#!/bin/bash
mkdir graphy-UI && cd graphy-UI
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
