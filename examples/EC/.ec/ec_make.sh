#!/bin/bash

if [ -d ".ec/build" ]
then
  cd .ec/build
else
  mkdir .ec/build
  cd .ec/build
fi

if [ -f ".ec/build/ec" ]
then
  rm -f build/ec
fi

if [ -f ".ec/build/libEC.so" ]
then
  rm -f build/libEC.so
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug

make -j${nproc}

cd ..

if [ -f "build/ec" ]
then
  cp -f build/ec ../ec
fi

if [ -f "build/libEC.so" ]
then
  cp -f build/libEC.so ../libEC.so
fi
