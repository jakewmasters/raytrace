# Makefile for Raytracer

CC=mpicc
CFLAGS=-Wall
EXEC=mpiexec

raytrace: raytrace.o
	$(CC) $< vec3.c -o $@

exec:
	$(EXEC) -np 2 ./raytrace -o test.ppm

.PHONY: clean
clean:
	$(RM) *.o