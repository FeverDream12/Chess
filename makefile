g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all: ./bin/chess.exe

-include build/src/*.d

./bin/chess.exe: ./build/main.o ./build/Board.o ./build/move.o
	$(g) $(CFLAGS) -o ./bin/chess.exe ./build/main.o ./build/move.o ./build/Board.o -lm

./build/main.o: ./src/main.cpp ./src/headerFile.h
	$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/Board.o: ./src/Board.cpp ./src/headerFile.h
	$(g) $(CFLAGS) -o ./build/Board.o -c ./src/Board.cpp -lm

./build/move.o: ./src/move.cpp ./src/headerFile.h
	$(g) $(CFLAGS) -o ./build/move.o -c ./src/move.cpp -lm

clean:
	rm -rf build/*.o build/*.d

run:
	./bin/chess.exe
