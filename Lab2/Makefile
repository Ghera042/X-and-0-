CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = tictactoe
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp GameEngine.hpp Renderer.hpp Listener.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
