#!/bin/bash
# PhySim Project Launcher
# Usage: source scripts/physim.bash (to stay in app directory)
# Or: ./scripts/physim.bash (builds but returns to original directory)

# Determine if we're being sourced or executed
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    # Being executed - need to cd to project root
    cd "$(dirname "$0")/.." || exit 1
else
    # Being sourced - check if we're in project root
    if [[ ! -f "CMakeLists.txt" ]]; then
        echo "Error: Please run from PhySim project root directory"
        return 1
    fi
fi

echo "[PhySim] Starting build and setup..."

# Set environment variable to communicate execution context to child scripts
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    export PHYSIM_EXECUTION_MODE="executed"
else
    export PHYSIM_EXECUTION_MODE="sourced"
fi

source scripts/setupBuild.bash
source scripts/setupRun.bash
source scripts/buildAndInstall.bash

# Add current bin directory to PATH since we're now in app directory
export PATH="$PWD/bin:$PATH"
