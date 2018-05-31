#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *a, *b, *c;
int n;

int main() {
	srand((unsigned int) time(NULL));

	for (int i = 64; i <= 1024; i *= 2) {
		init(i);
		run_i_j_k();
		init(i);
		run_j_i_k();
		init(i);
		run_j_k_i();
		init(i);
		run_k_i_j();
		init(i);
		run_k_j_i();
		init(i);
		run_i_k_j();
		init(i);
		run_i_j_k_tiled();
		init(i);
		run_i_k_j_tiled();
	}

	return 0;
}

void init(int x) {

	n = x;
	a = (float *) malloc(n * n * sizeof(float));
	b = (float *) malloc(n * n * sizeof(float));
	c = (float *) malloc(n * n * sizeof(float));

	// initialize a and b with random float values, c= 0
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			*(a + i * n + j) = (float) rand() / (float) (RAND_MAX);
			*(b + i * n + j) = (float) rand() / (float) (RAND_MAX);
			*(c + i * n + j) = 0;
		}

}

void run_i_j_k() {
	//first run

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("i_j_k\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_j_i_k() {
	//first run

	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("j_i_k\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_j_k_i() {
	//first run

	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("j_k_i\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_k_i_j() {
	//first run
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("k_i_j\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_k_j_i() {
	//first run

	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("k_j_i\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_i_k_j() {
	//first run

	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n; j++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	//second run
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n; j++)
				*(c + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
		}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("i_k_j\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));

}

void run_i_j_k_tiled(){

// first run
// i and j iterations blocked by a factor of two
for (int i = 0; i < n; i += 2)
{
    for (int j = 0; j < n; j += 2)
    {
        float acc00, acc01, acc10, acc11;
		acc00 = acc01 = acc10 = acc11 = 0;
        for (int k = 0; k < n; k++)
        {
            acc00 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 0) + k);
            acc01 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 0) + k);
            acc10 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 1) + k);
            acc11 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 1) + k);
        }
                *(c + (i * n + 0) + (j + 0)) = acc00;
                *(c + (i * n + 0) + (j + 1)) = acc01;
                *(c + (i * n + 1) + (j + 0)) = acc10;
                *(c + (i * n + 1) + (j + 1)) = acc11;
    }
}
// second run
	clock_t t;
	t = clock();
for (int i = 0; i < n; i += 2)
{
    for (int j = 0; j < n; j += 2)
    {
        float acc00, acc01, acc10, acc11;
		acc00 = acc01 = acc10 = acc11 = 0;
        for (int k = 0; k < n; k++)
        {
            acc00 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 0) + k);
            acc01 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 0) + k);
            acc10 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 1) + k);
            acc11 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 1) + k);
        }
                *(c + (i * n + 0) + (j + 0)) = acc00;
                *(c + (i * n + 0) + (j + 1)) = acc01;
                *(c + (i * n + 1) + (j + 0)) = acc10;
                *(c + (i * n + 1) + (j + 1)) = acc11;
    }
}
	
	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("i_j_k_tiled\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));
}


void run_i_k_j_tiled(){

// first run
// i and k iterations blocked by a factor of two
for (int i = 0; i < n; i += 2)
{
    for (int k = 0; k < n; k += 2)
    {	
        float acc00, acc01, acc10, acc11;
		acc00 = acc01 = acc10 = acc11 = 0;
        for (int j = 0; j < n; j++)
        {
            acc00 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 0) + k);
            acc01 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 0) + k);
            acc10 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 1) + k);
            acc11 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 1) + k);
        }
                *(c + (i * n + 0) + (k + 0)) = acc00;
                *(c + (i * n + 0) + (k + 1)) = acc01;
                *(c + (i * n + 1) + (k + 0)) = acc10;
                *(c + (i * n + 1) + (k + 1)) = acc11;
    }
}
// second run
	clock_t t;
	t = clock();
for (int i = 0; i < n; i += 2)
{
    for (int k = 0; k < n; k += 2)
    {	
        float acc00, acc01, acc10, acc11;
		acc00 = acc01 = acc10 = acc11 = 0;
        for (int j = 0; j < n; j++)
        {
            acc00 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 0) + k);
            acc01 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 0) + k);
            acc10 += *(b + (k * n) + (j + 0)) * *(a + (i * n + 1) + k);
            acc11 += *(b + (k * n) + (j + 1)) * *(a + (i * n + 1) + k);
        }
                *(c + (i * n + 0) + (k + 0)) = acc00;
                *(c + (i * n + 0) + (k + 1)) = acc01;
                *(c + (i * n + 1) + (k + 0)) = acc10;
                *(c + (i * n + 1) + (k + 1)) = acc11;
    }
}
	
	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("i_k_j_tiled\n");
	printf("n = %d \n", n);
	printf("Time = %f s \n", time_taken);
	printf("FLOPS = %.2f \n\n", (2 * powf(n, 3)) / (time_taken * 10000000));
}
