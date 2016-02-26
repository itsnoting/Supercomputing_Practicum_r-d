openmp.out: openMp_test.c
	gcc -fopenmp -O3 -msse2 openMp_test.c -o openmp.out
	`/usr/bin/sdl-config --cflags --libs'