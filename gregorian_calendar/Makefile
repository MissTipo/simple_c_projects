CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Wno-unused-parameter
TARGET = calendar

all: $(TARGET)

$(TARGET): calendar.c
	$(CC) $(CFLAGS) -o $(TARGET) calendar.c

clean:
	rm -f $(TARGET)
