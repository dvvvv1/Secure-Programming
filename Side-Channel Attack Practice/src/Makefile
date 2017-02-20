all: profiling calibration exploitation
profiling: profiling.c cacheutils.h
	gcc -std=gnu11 -O2 -o $@ $< -lrt -pthread -lxdo -lX11
calibration: calibration.c cacheutils.h
	gcc -std=gnu11 -O2 -o $@ $@.c
exploitation.c: exploitation.c cacheutils.h
	gcc -std=gnu11 -O2 -o $@ $@.c

