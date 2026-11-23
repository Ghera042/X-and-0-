CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
TARGET = tictactoe

SRC = main.cpp GameEngine.cpp Listener.cpp Renderer.cpp Computer.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o *.d $(TARGET)

-include $(DEP)

.PHONY: all run clean
