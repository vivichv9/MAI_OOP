.PHONY: build run test-all test_octagon test_point test_square test_triangle test_vector clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all


run:
	./build/*_exe


test-vector:
	./build/*test_vector


test-octagon:
	./build/*test_octagon


test-point:
	./build/*test_point


test-square:
	./build/*test_square


test-triangle:
	./build/*test_triangle

test-all: test_octagon test_point test_square test_triangle test_vector

clean:
	rm -rf ./build/
