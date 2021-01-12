#!/bin/bash

set -x

sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake -DGTEST_CREATE_SHARED_LIBRARY=1 -DGTEST_LINKED_AS_SHARED_LIBRARY=1 
sudo make
sudo cp *.a /usr/lib
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a
