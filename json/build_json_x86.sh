#!/bin/sh

SRC_DIR=/home/sjc/json/json-c-0.12
OUT_DIR=/home/sjc/json/out

echo "sjc==>make .a"
cd $SRC_DIR/
export CC=gcc

./configure --host=x86  CC=gcc --prefix=$OUT_DIR/json_x86


make
make install
make clean
