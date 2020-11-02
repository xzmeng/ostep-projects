CC = gcc
CFLAGS = -Wall -Werror

wcat: wcat.c
	$(CC) $(CFLAGS) -o wcat wcat.c


.PHONY: test
test: wcat
	./test-wcat.sh