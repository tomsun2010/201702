#!/bin/sh


SRC_DIR=/home/sjc/curl/curl-7.49.0
OUT_DIR=/home/sjc/curl/out

cd $SRC_DIR/


./configure CC=gcc --prefix=$OUT_DIR/curl_x86


make 
make install
make clean
