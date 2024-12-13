#!/bin/bash

# Function to recursively display files and directories
list_files() {
    for item in "$1"/*; do
        if [ -d "$item" ]; then
            echo "Directory: $item"
            list_files "$item"  # Recursively list subdirectories
        else
            echo "	File: $item"
        fi
    done
}

# Call the function with the specified directory
directory=$1
if [ -z "$directory" ]; then
    echo "Please provide a directory."
    exit 1
fi

list_files "$directory"

