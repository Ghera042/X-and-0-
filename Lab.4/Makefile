CXX = g++
CXXFLAGS = -Wall -Wextra

OBJ = main.o GameEngine.o Listener.o Renderer.o

tictactoe: $(OBJ)
	$(CXX) $(OBJ) -o tictactoe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o tictactoe
