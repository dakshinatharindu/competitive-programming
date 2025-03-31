TARGET=plateMgmt
CC=g++
CFLAGS=-Wall -std=c++17
DEBUG_FLAGS=-g -O0

# Source files
SRCS=main.cpp red_black_tree.cpp

# Header files
HEADERS=red_black_tree.h

# Object files
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Build the target executable with debugging flags
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean debug