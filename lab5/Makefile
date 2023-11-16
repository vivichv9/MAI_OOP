.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run:
	./build/*_exe

clean:
	rm -rf ./build

test-list:
	./build/test/*_test_list

test-allocator:
	./build/test/*_test_allocator

