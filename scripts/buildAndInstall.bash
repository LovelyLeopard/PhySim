#!/bin/bash
mkdir -p build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../app
make -j${nproc} install
cd ../app

# Check execution context - either from parent physim.bash or own detection
if [[ "$PHYSIM_EXECUTION_MODE" == "executed" || "${BASH_SOURCE[0]}" == "${0}" ]]; then
    # Either physim.bash was executed OR this script is being executed directly
    echo "[buildAndInstall] Build complete."
    echo "[PhySim] Ready to run! Execute: physim"
else
    # Either physim.bash was sourced OR this script is being sourced directly
    echo "[buildAndInstall] Build complete. You are in app directory."
    echo "[PhySim] Ready to run! Execute: physim"
fi
