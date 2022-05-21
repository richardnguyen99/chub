CC	:= gcc
CCFLAGS := -g -O0 -Wall -Werror

SRC := scheduler.c fcfs.c
HDR := fcfs.h
OBJ := $(patsubst %.c, %.o, $(SRC))

all: scheduler

scheduler: $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c $(HDR)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf scheduler *.o
