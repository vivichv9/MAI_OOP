.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

clean:
	rm -rf ./build

test-list:
	./build/test/*_test_octagon

test-allocator:
	./build/test/*_test_point

