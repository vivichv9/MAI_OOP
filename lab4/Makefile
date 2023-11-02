.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

clean:
	rm -rf ./build

test-octagon:
	./build/test/*_test_octagon

test-point:
	./build/test/*_test_point

test-square:
	./build/test/*_test_square

test-triangle:
	./build/test/*_test_triangle