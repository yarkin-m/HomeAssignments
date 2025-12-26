CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = assignment2b
SOURCES = main.cpp rpn.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run