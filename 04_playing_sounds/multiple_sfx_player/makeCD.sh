#! /bin/sh
#automating script for making CD games

DIR=$PWD
PROJECT_NAME="project_name"
TARGET="main.elf"

# go to build directory
# make clean
make

lxdream $TARGET
