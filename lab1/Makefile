.PHONY: build run test clean

build: clean
	mkdir build
	git submodule init
	git submodule update
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test:
	./build/*_test

clean:
	rm -rf ./build/
