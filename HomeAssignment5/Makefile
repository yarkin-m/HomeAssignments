CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -std=c++17 -Wall -Wextra -I. -pthread -lgtest -lgtest_main

MAIN_SRC = main.cpp
MAIN_EXE = demo

SRC = rational.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = rational.h matrix.h

TEST_SRCS = rational_invariant_test.cpp \
            rational_matrix_addition_test.cpp \
            rational_matrix_multiplication_test.cpp \
            rational_scalar_multiplication_test.cpp \
            rational_transpose_test.cpp \
            test_matrix.cpp

TEST_EXES = $(TEST_SRCS:.cpp=)

all: $(MAIN_EXE) $(TEST_EXES)

$(MAIN_EXE): $(MAIN_SRC) $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_SRC) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%test: %test.cpp $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) -pthread $< $(OBJ) -o $@ -lgtest -lgtest_main

test_matrix: test_matrix.cpp $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) -pthread $< $(OBJ) -o $@ -lgtest -lgtest_main

test: $(TEST_EXES)
	@for test in $(TEST_EXES); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done

clean:
	rm -f $(MAIN_EXE) $(TEST_EXES) *.o

run: $(MAIN_EXE)
	./$(MAIN_EXE)

.PHONY: all test clean run