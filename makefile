g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

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

test: bin/chess-test

bin/chess-test: build/test/main.o build/test/move.o
		$(g) -o bin/chess-test build/test/main.o build/test/move.o

build/test/main.o: test/main.cpp
		$(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp


build/test/move.o: src/move.cpp
		$(g) $(CFLAGS) -o build/test/move.o -c src/move.cpp

clean:
	rm -rf build/*.o build/*.d

testRun:
	./bin/chess-test

run:
	./bin/chess.exe
