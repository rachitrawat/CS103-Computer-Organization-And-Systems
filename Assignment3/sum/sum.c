#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Create a short form for 64-bit integer
typedef unsigned long long uint64_t;
uint64_t *a, *b, *c;
uint64_t count = 512 * 32768;

int main() {

	srand(time(NULL));   // should only be called once

	// allocate space for the array
	a = (uint64_t *) malloc(sizeof(uint64_t) * count);
	b = (uint64_t *) malloc(sizeof(uint64_t) * count);
	c = (uint64_t *) malloc(sizeof(uint64_t) * count);

	// generate random numbers
	for (uint64_t i = 0; i < count; i++) {
		a[i] = rand();
		b[i] = rand();
	}

	// 512 * 1 , 512 * 5001 , 512 * 10001 .....
	for (int i = 1; i <= 32768; i += 5000) {
		calc(512 * i);
	}

	return 0;
}

void calc(int n) {

	// time boundaries
	struct timeval start, end;

	uint64_t total_time = 0;
	for (int iter = 0; iter < 1000; iter++) {

		// main loop to measure
		gettimeofday(&start, NULL);

		for (uint64_t i = 0; i < n; i++) {
			c[i] = a[i] + b[i];
		}

		gettimeofday(&end, NULL);

		// compute how much time it took
		uint64_t diff = (end.tv_sec * 1000000 + end.tv_usec)
				- (start.tv_sec * 1000000 + start.tv_usec);
		total_time += diff;
	}

	total_time /= 1000;

	// print the sum and time
	printf("Time = %lld us\n", total_time);

}

