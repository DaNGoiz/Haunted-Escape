CC=g++
CFLAGS=-Wall -g
LIBS=

# Object files for lowercase .cpp (utility) files
UTILS_OBJ=generate_map.o get_map.o get_player.o set_map.o set_player.o timer.o

# Object files for uppercase .cpp (main) files and frame.cpp
MAIN_OBJ=Frame.o GameStatus.o InGamePlayerMove.o InShopPlayerMove.o printEndMenu.o printStartMenu.o printVictoryMenu.o

# Final executable
EXEC=game

all: $(EXEC)

$(EXEC): $(UTILS_OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

Frame.o: frame.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

GameStatus.o: GameStatus.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

InGamePlayerMove.o: InGamePlayerMove.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

InShopPlayerMove.o: InShopPlayerMove.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

printEndMenu.o: printEndMenu.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

printStartMenu.o: printStartMenu.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

printVictoryMenu.o: printVictoryMenu.cpp $(UTILS_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)


# Rules for utility object files
generate_map.o: generate_map.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

get_map.o: get_map.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

get_player.o: get_player.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

set_map.o: set_map.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

set_player.o: set_player.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

timer.o: timer.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -f $(UTILS_OBJ) $(MAIN_OBJ) $(EXEC)

.PHONY: all clean
