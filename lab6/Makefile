.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run: build
	./build/*_exe

clean:
	rm -rf ./build