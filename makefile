CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lX11

all: switch_screen.c
	$(CC) $(CFLAGS) -o switch_screen switch_screen.c $(LDFLAGS)
