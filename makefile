#!/usr/local/env bash

export PATH="~/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH"

all:
	mkdir -p _builds
	cmake .
	make -C _builds
	cd _builds && ./test_bin
