INCLUDE_PATH = -I./src
OUTPUT_DIR = ./output

ALL_OBJ_O = $(OUTPUT_DIR)/testMakefile.o $(OUTPUT_DIR)/main.o
TARGET = $(OUTPUT_DIR)/main.out

CC = clang++ $(INCLUDE_PATH)

start: prepare $(TARGET)

prepare:
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@ $(ALL_OBJ_O)

$(OUTPUT_DIR)/testMakefile.o: ./src/testMakefile.cpp
	$(CC) -c $< -o $@

$(OUTPUT_DIR)/main.o: ./src/main.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)