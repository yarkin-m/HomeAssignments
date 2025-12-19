CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

all: demo tests

demo: Alliance.cpp Weapon.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Dinobot.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

tests: Alliance.cpp Weapon.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Dinobot.cpp test_transformers.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

run: demo
	./demo

test: tests
	./tests

clean:
	rm -f *.o demo tests

.PHONY: all clean run test