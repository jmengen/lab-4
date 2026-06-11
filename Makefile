CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iinclude
TARGET = lab4
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj $(TARGET)