#!/bin/bash

mkdir -p build
cd build
cmake ..
make -j

cd ..
mkdir -p target
cp ./build/orion_airlines ./target/orion_airlines
