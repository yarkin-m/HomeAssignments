CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic
TARGET = transformers
SRC = $(wildcard *.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run