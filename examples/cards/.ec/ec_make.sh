#!/bin/bash

if [ ! -d .ec/build ]
then
  mkdir .ec/build
fi

if [ -f .ec/build/cards ]
then
  rm -f .ec/build/cards
fi

if [ -f cards ]
then
  rm -f cards
fi

cd .ec/build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug

make -j${nproc}

cd ../..

if [ -f .ec/build/cards ]
then
  cp -f .ec/build/cards cards
  ln -sf ../EC/ec ec
else
  echo 'Error: Unable to build'
fi

