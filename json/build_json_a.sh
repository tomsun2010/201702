#!/bin/sh

SRC_DIR=/home/sjc/json/json-c-0.12
OUT_DIR=/home/sjc/json/out

echo "sjc==>make .a"
cd $SRC_DIR/
export CC=arm-linux-gnueabihf-gcc

./configure --host=arm CC=arm-linux-gnueabihf-gcc --prefix=$OUT_DIR/json_a


make
make install
make clean
