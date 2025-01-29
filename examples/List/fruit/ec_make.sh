#!/bin/bash

if [ -d "build" ]; then
  rm -r build
fi

mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../

make -j${nproc}

if [ -f "fruit" ]; then
  cp fruit ../bin/
  cd ..
  rm -r build
else
  echo "Error: cannot build"
fi
