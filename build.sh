#!/bin/bash

read BUILD_TARGET
echo "building ${BUILD_TARGET} ..."

clang++ -o bin/${BUILD_TARGET[@]//.cpp/} ${BUILD_TARGET}

echo "${BUILD_TARGET} was built"