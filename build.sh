#!/bin/bash

echo "enter file name is needed to compile"
read BUILD_TARGET
echo "building ${BUILD_TARGET} ..."

clang++ -O2 -Werror -o bin/${BUILD_TARGET[@]//.cpp/} ${BUILD_TARGET}

echo "${BUILD_TARGET} was built"