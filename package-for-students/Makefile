# Compiler + flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Output executable name
TARGET := prog

# Source files
SRCS := main.cpp system.cpp disk.cpp
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile step
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run (creates confs/ if needed)
run: $(TARGET)
	mkdir -p confs
	./$(TARGET)

# Clean build artifacts + output
clean:
	rm -f $(OBJS) $(TARGET)

# Clean configs only
clean-confs:
	rm -rf confs

.PHONY: all run clean clean-confs