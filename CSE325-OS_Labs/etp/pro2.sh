#!/bin/bash

read dir

for file in "$dir"/*
do
	echo "$file"
done
