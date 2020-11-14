#!/bin/bash
sudo apt install -y python3-pip git cmake gcc g++ 
pip install conan
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan 

