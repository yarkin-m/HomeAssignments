CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

all: demo tests

demo: rational.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tests: rational.o test_matrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

rational.o: rational.cpp rational.h matrix.h
	$(CXX) $(CXXFLAGS) -c rational.cpp -o rational.o

main.o: main.cpp rational.h matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

test_matrix.o: test_matrix.cpp rational.h matrix.h
	$(CXX) $(CXXFLAGS) -c test_matrix.cpp -o test_matrix.o

run: demo
	./demo

test: tests
	./tests

clean:
	rm -f *.o demo tests

.PHONY: all clean run test