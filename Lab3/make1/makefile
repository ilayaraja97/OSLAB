#
# My makefile
# Compile SOURCES into OUT_FILE
#
# Try following on command line
# make
# make clean
# make rebuild
# make all
#
# Try tab key after make, e.g. make re<tab>
#

CC := gcc
CFLAGS := -fopenmp -Wall
SOURCES := openmp_eg.c
OUT_FILE := a.out

build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUT_FILE) $(SOURCES)

clean:
	rm -f $(OUT_FILE)

rebuild: clean build

all: build

