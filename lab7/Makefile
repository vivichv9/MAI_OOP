.PHONY: build test

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run:
	./build/*_exe

clean:
	rm -rf ./build

test:
	./build/test/*_test