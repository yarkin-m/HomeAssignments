CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = assignment2a

SOURCES = main.cpp reverse.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean rebuild run