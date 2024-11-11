#!/bin/bash

# Check if a directory name is provided as an argument
if [ -z "$1" ]; then
    echo "Error: No directory name provided."
    echo "Usage: $0 <directory_name> [file_count]"
    exit 1
fi

# Directory name from the command argument
S="$1"

# File count from the second argument (default to 7 if not provided)
file_count=${2:-7}

# Original file directory and name
origin_dir="Library"
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

# Get the current date and time in "YYYY-MM-DD HH:MM:SS" format
current_date=$(date +"%Y-%m-%d %H:%M:%S")

# Generate file names (A.cpp, B.cpp, ..., up to the specified file count)
new_files=()
for ((i=0; i<file_count; i++)); do
    file_letter=$(printf "\\x$(printf %x $((65 + i)) )")  # Convert to letter (A, B, C, ...)
    new_files+=("$file_letter.cpp")
done

# Loop to copy the original file to new files with "{contest}", "{problem}", and "{date}" replaced
for new_file in "${new_files[@]}"; do
    # Extract the file name without extension for "{problem}" replacement
    problem_name="${new_file%.cpp}"
    
    # Use sed to replace "{contest}" with "$S", "{problem}" with "$problem_name", and "{date}" with "$current_date"
    sed -e "s/{contest}/$S/g" -e "s/{problem}/$problem_name/g" -e "s/{date}/$current_date/g" "$origin_dir/$origin_file" > "$new_dir/$new_file"
    
    echo "Copied $origin_file to $new_file in $new_dir with {contest} replaced by $S, {problem} replaced by $problem_name, and {date} replaced by $current_date"
done

echo "All files have been successfully copied."
