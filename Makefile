# Makefile for Raytracer

CC=mpicc
CFLAGS=-Wall
EXEC=mpiexec

raytrace: raytrace.o
	$(CC) $< -o $@

exec:
	$(EXEC) -np 2 ./raytrace -o test.ppm

.PHONY: clean
clean:
	$(RM) *.o