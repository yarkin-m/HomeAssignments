<<<<<<< HEAD
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = assignment2a
SOURCES = main.cpp reverse.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp reverse.h
	$(CXX) $(CXXFLAGS) -c main.cpp

reverse.o: reverse.cpp reverse.h
	$(CXX) $(CXXFLAGS) -c reverse.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET) input.bin output.bin

.PHONY: all clean rebuild run test
=======
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
>>>>>>> c13282286ece2ce377209c916f47f8aecf37b899
