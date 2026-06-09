CC=gcc
CFLGS=-Wall -Wextra
TARGET=snake
OBJ=main.o snake.o
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
main.o: main.c snake.h
	$(CC) $(CFLAGS) -c main.c
snake.o: snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c
clean:
	del *.o $(TARGET).exe