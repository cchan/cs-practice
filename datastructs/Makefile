.DEFAULT_GOAL=all
CC = g++
CFLAGS = -c -Og -g -DDEBUG -Wall -std=gnu++11
SRC = $(wildcard *.cpp)
BUILD_DIR = build
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
EXECUTABLE = $(BUILD_DIR)/datastructs
MAKEDEPEND = g++ -M $(CFLAGS) -o $*.Td $<

.PHONY: all
all: dirs $(EXECUTABLE)

.PHONY: dirs
dirs: $(BUILD_DIR)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# The executable depends on all of the .o files
$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Each o file depends on its respective C++ file.
$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

%.d : %.cpp
	$(MAKEDEPEND)
	@sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' < $*.Td > $@; \
	  rm -f $*.Td; [ -s $@ ] || rm -f $@

include $(SRCS:.cpp=.d)
