CC = clang
CXX = clang++
GENERATOR = Ninja

TARGET = dlog
BUILD_DIR = build
RELEASE_DIR = build-release
CONFIG = Debug

all: prepare
	cmake --build $(BUILD_DIR) --config $(CONFIG) --target all

prepare:
	cmake -DCMAKE_BUILD_TYPE:STRING=Debug -S. -B$(BUILD_DIR) -G $(GENERATOR)

build:
	cmake --build $(BUILD_DIR) --config $(CONFIG) --target $(TARGET)

release:
	cmake -DCMAKE_BUILD_TYPE:STRING=Release -S. -B$(RELEASE_DIR) -G $(GENERATOR)
	cmake --build $(RELEASE_DIR) --config Release --target $(TARGET)

run:
	./build/bin/$(TARGET) $(ARGS)

test:
	cd build/tests && GTEST_COLOR=1 ctest --output-on-failure $(ARGS)

format:
	cmake --build build --target clang-format

clean:
	rm -rf build

.PHONY: build