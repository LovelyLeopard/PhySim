#!/bin/bash
mkdir -p build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../app
make -j${nproc} install
cd ../app
echo "[buildAndInstall] Build complete. You are in app directory."