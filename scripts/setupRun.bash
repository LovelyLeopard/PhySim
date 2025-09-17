#!/bin/bash
# Add both possible bin paths to PATH to handle different working directories
export PATH="$PWD/app/bin:$PWD/bin:$PATH"
echo "[setupRun] Runtime environment ready."