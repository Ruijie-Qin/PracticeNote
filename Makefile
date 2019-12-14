INCLUDE_PATH = -I./src
OUTPUT_DIR = ./output

ALL_OBJ_O = $(OUTPUT_DIR)/ReverseListSolution.o $(OUTPUT_DIR)/LeetCodeApplication.o
TARGET = $(OUTPUT_DIR)/LeetCodeApplication.out

CC = clang++ $(INCLUDE_PATH) -std=c++11

start: prepare $(TARGET)

prepare:
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@ $(ALL_OBJ_O)

$(OUTPUT_DIR)/ReverseListSolution.o: ./src/ReverseListSolution.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/LeetCodeApplication.o: ./src/LeetCodeApplication.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)