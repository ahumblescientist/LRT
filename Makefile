CFILES = main.cpp vec.cpp 
HFILES = Makefile vec.h color.h hittable.h sphere.h hittable_list.h
FILES = $(CFILES) $(HFILES)
CC = clang++
OUT = bin/main
FLAGS = -ggdb3 -O0 -lm -o $(OUT)


main: $(FILES)
	$(CC) $(CFILES) $(FLAGS)
