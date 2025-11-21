CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = app

SOURCES = main.cpp hello.cpp
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