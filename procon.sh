#!/bin/bash

# Check if a directory name is provided as an argument
if [ -z "$1" ]; then
    echo "Error: No directory name provided."
    echo "Usage: $0 <directory_name>"
    exit 1
fi

# Directory name from the command argument
S="$1"

# Original file directory and name
origin_dir="library"
origin_file="origin.cpp"

# New directory
new_dir="$S"

# Check if the original file exists
if [ ! -f "$origin_dir/$origin_file" ]; then
    echo "Error: $origin_file does not exist in $origin_dir"
    exit 1
fi

# Create the new directory if it does not exist
if [ ! -d "$new_dir" ]; then
    mkdir -p "$new_dir"
    echo "Created directory $new_dir"
fi

# List of new file names
new_files=("A.cpp" "B.cpp" "C.cpp" "D.cpp" "E.cpp" "F.cpp" "G.cpp" "H.cpp")

# Loop to copy the original file to new files
for new_file in "${new_files[@]}"; do
    cp "$origin_dir/$origin_file" "$new_dir/$new_file"
    echo "Copied $origin_file to $new_file in $new_dir"
done

echo "All files have been successfully copied."
