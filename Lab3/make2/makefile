# makefile

CC := gcc
CFLAGS := -Wall
SOURCES := student_records.h student_records.c
OUT_FILE := a.out

build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUT_FILE) $(SOURCES)

clean:
	rm -f $(OUT_FILE)

rebuild: clean build

all: build

