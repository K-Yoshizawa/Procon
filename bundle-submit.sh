#!/bin/bash

set -euo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: $0 <source_file> [output_file]" >&2
    exit 1
fi

source_file="$1"
output_file="${2:-submit.cpp}"
timestamp=$(date +"%Y/%m/%d %H:%M:%S")

oj-bundle "$source_file" > "$output_file" 2>/dev/null
DATE="$timestamp" perl -0pi -e 's/\{date\}/$ENV{DATE}/g' "$output_file"