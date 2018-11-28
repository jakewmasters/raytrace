# Makefile for Raytracer

CC=gcc
CFLAGS=-Wall

raytrace: raytrace.o
	$(CC) $< vec3.c ray.c -o $@ -lm

exec:
	./raytrace -o test.ppm

.PHONY: clean
clean:
	$(RM) *.o