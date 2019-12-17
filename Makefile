INCLUDE_PATH = -I./src
OUTPUT_DIR = ./output

ALL_OBJ_O = $(OUTPUT_DIR)/ReverseListSolution.o $(OUTPUT_DIR)/StackQueueSolution.o $(OUTPUT_DIR)/MapSetSolution.o $(OUTPUT_DIR)/TreeGraphSolution.o $(OUTPUT_DIR)/LeetCodeApplication.o
TARGET = $(OUTPUT_DIR)/LeetCodeApplication.out

CC = clang++ $(INCLUDE_PATH) -std=c++11 -g

start: prepare $(TARGET)

prepare:
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@ $(ALL_OBJ_O)

$(OUTPUT_DIR)/ReverseListSolution.o: ./src/ReverseListSolution.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/StackQueueSolution.o: ./src/StackQueueSolution.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/MapSetSolution.o: ./src/MapSetSolution.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/TreeGraphSolution.o: ./src/TreeGraphSolution.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/LeetCodeApplication.o: ./src/LeetCodeApplication.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)