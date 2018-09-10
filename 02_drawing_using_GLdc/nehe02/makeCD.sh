#! /bin/sh
#automating script for making CD games

DIR=$PWD
PROJECT_NAME="project_name"
TARGET="nehe02.elf"

# go to build directory
make

lxdream $TARGET
