CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = calendar

all: $(TARGET)

$(TARGET): calendar.c
	$(CC) $(CFLAGS) -o $(TARGET) calendar.c

clean:
	rm -f $(TARGET)
