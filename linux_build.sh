#!/bin/bash
if [ -d "build" ] 
then
	rm build -r
fi
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
