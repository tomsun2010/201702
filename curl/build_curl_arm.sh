#!/bin/sh


SRC_DIR=/home/sjc/curl/curl-7.49.0
OUT_DIR=/home/sjc/curl/out

cd $SRC_DIR/
export CC=arm-linux-gnueabihf-gcc

./configure --host=arm  CC=arm-linux-gnueabihf-gcc --prefix=$OUT_DIR/curl_arm --disable-debug

make clean
make 
make install
make clean
