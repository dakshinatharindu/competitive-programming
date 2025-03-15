TARGET=plateMgmt
CC=g++
CFLAGS=-g -Wall -std=c++17

# Source files
SRCS=main.cpp red_black_tree.cpp

# Header files
HEADERS=red_black_tree.h

# Object files
OBJS=$(SRCS:.cpp=.o)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean