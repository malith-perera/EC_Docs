#!/bin/bash

if [ ! -d .ec/build ]
then
  mkdir .ec/build
fi

cd .ec/build

if [ -f ec ]
then
  rm -f ec
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release

make -j${nproc}

cd ../..

if [ -f .ec/build/test ]
then
  cp -f .ec/build/test test
  ln -sf ../ec ./ec
else
  echo "Error: Unable to build"
fi
