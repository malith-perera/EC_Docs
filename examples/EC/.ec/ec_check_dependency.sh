#!/bin/bash

echo "Checking for dependencies..."
echo "\n"

compilerFound=""

if type gcc; then
  $compiler="gcc"
  echo "gcc found"
elif type clang; then
  $compiler="clang"
  echo "clang found"
fi

if $compiler; then
  echo "EC get $compiler as the default compiler"
elif
  echo "Compiler not"
fi
