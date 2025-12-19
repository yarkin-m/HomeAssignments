CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

SRC = Alliance.cpp Weapon.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Dinobot.cpp
HEADERS = Alliance.h Weapon.h Transformer.h Autobot.h Decepticon.h Dinobot.h

OBJ = $(SRC:.cpp=.o)
TEST_OBJ = test_transformers.o
MAIN_OBJ = main.o

all: demo test_program

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

demo: $(OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(MAIN_OBJ)


test_program: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(TEST_OBJ) $(GTEST_FLAGS)


run: demo
	./demo

test: test_program
	./test_program

clean:
	rm -f *.o demo test

.PHONY: all clean run test