.PHONY: build run test-vector test-six clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test-six:
	./build/*_test_six

test-vector:
	./build/*_test_vector

clean:
	rm -rf ./build/
