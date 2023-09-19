.PHONY: build run test clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test:
	./build/*_unittests

clean:
	rm -rf ./build/