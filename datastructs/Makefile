.DEFAULT_GOAL=all
CC=g++
CFLAGS=-c -Og -g -DDEBUG -Wall -std=gnu++11
SRC=$(wildcard *.cpp)
BUILD_DIR=build
OBJ=$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
EXECUTABLE=$(BUILD_DIR)/datastructs

all: $(EXECUTABLE)
	@mkdir -p $(BUILD_DIR)

# Automatic collection of Include Dependencies
.PHONY: depend
depend: dirs $(BUILD_DIR)/.depend
	$(BUILD_DIR)/.depend: $(SRC)
	rm -f $(BUILD_DIR)/.depend
	$(CC) $(CFLAGS) -MM $^ -MF $(BUILD_DIR)/.depend;

# The executable depends on all of the .o files
$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Each o file depends on its respective C++ file.
$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

-include $(OBJ:.o=.d)
