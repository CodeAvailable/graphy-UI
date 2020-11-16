#!/bin/bash
sudo apt install -y python3-pip git cmake gcc g++ xorg-dev libx11-xcb-dev libxcb-render0-dev libxcb-render-util0-dev \
libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev  libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev \
libxcb-xfixes0-dev libxcb-xinerama0-dev m4 libgl1-mesa-dev
pip install conan mako
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan 

