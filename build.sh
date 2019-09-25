#!/bin/bash

BUILD_TARGET=$1

echo "building ${BUILD_TARGET} ..."

clang++ -O2 -Werror -o bin/${BUILD_TARGET[@]//.cpp/} ${BUILD_TARGET}

echo "${BUILD_TARGET} was built"