INCLUDE_PATH = -I./src
BUILD_DIR = ./output

ALL_OBJ_O = $(BUILD_DIR)/testMakefile.o $(BUILD_DIR)/main.o
TARGET = $(BUILD_DIR)/main.out

CC = clang++ $(INCLUDE_PATH)

start: prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@ $(ALL_OBJ_O)

$(BUILD_DIR)/testMakefile.o: ./src/testMakefile.cpp
	$(CC) -c $< -o $@

$(BUILD_DIR)/main.o: ./src/main.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)