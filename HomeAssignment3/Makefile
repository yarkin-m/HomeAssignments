CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
TARGET = assignment3

SRC_DIR = src
SRCS = $(SRC_DIR)/transformers/Weapon.cpp \
       $(SRC_DIR)/transformers/Alliance.cpp \
       $(SRC_DIR)/transformers/Transformer.cpp \
       $(SRC_DIR)/transformers/Autobot.cpp \
       $(SRC_DIR)/transformers/Decepticon.cpp \
       $(SRC_DIR)/transformers/Dinobot.cpp \
       $(SRC_DIR)/tests/WeaponTest.cpp \
       $(SRC_DIR)/tests/AllianceTest.cpp \
       $(SRC_DIR)/tests/TransformerTest.cpp \
       $(SRC_DIR)/tests/AutobotTest.cpp \
       $(SRC_DIR)/tests/DecepticonTest.cpp \
       $(SRC_DIR)/tests/DinobotTest.cpp \
       main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(SRC_DIR)/transformers/*.o $(SRC_DIR)/tests/*.o

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET)

.PHONY: all clean run test