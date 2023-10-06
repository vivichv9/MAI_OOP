.PHONY: build run test-vector test-seven clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test-seven:
	./build/*_test_seven

test-vector:
	./build/*_test_vector

clean:
	rm -rf ./build/
