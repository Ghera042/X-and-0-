CXX = g++
AR = ar
CPPFLAGS =
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
SQLITE_LIBS = -lsqlite3

TARGET = tictactoe
OBJ = main.o Listener.o Renderer.o Computer.o

all: $(TARGET)

$(TARGET): $(OBJ) libengine.a libstorage.a
	$(CXX) $(OBJ) -L. -lstorage -lengine $(SQLITE_LIBS) -o $(TARGET)

libengine.a: GameEngine.o
	$(AR) rcs $@ $^

libstorage.a: Storage.o
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o *.d *.a $(TARGET)

-include $(wildcard *.d)

.PHONY: all run clean
