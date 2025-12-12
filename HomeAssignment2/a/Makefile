CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = assignment2a
SOURCES = main.cpp reverse.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
