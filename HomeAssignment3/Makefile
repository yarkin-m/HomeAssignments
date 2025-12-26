CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread


SRC = Alliance.cpp Weapon.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Dinobot.cpp
HEADERS = Alliance.h Weapon.h Transformer.h Autobot.h Decepticon.h Dinobot.h


OBJ = $(SRC:.cpp=.o)
TEST_OBJ = test_assignment4.o
MAIN_OBJ = main.o


TARGETS = demo tests

all: $(TARGETS)


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


demo: $(OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


tests: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)


run: demo
	./demo

test: tests
	./tests

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean run test