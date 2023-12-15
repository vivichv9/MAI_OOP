.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run: build
	./build/*_exe

clean:
	rm -rf ./build

test-factory:
	./build/tests/*_factory_test

test-log:
	./build/tests/*_log_test

test-square:
	./build/tests/*_square_test