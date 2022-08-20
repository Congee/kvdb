#!/usr/bin/env bash

set -eux -o pipefail

# 1. compile with -fprofile-instr-generate -fcoverage-mapping
# 2. LLVM_PROFILE_FILE='/tmp/test.profraw' ./build/tests/test_main
llvm_profdata_file=/tmp/test.profdata
llvm-profdata merge -sparse "$LLVM_PROFILE_FILE" -o $llvm_profdata_file
llvm-cov report ./build/kv -instr-profile=$llvm_profdata_file
llvm-cov show ./build/kv -instr-profile=$llvm_profdata_file -format=html > /tmp/coverage.html
llvm-cov export --instr-profile=$llvm_profdata_file --format=lcov ./build/kv > /tmp/coverage.lcov
