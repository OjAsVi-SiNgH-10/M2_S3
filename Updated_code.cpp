#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_THREADS 8
#define MAX 1000000

int data[MAX];
long global_sum = 0;

int main(int argc, char *argv[])
{ 
    int cores = omp_get_num_procs();
    omp_set_num_threads(NUM_THREADS);

    std::cout << "The number of cores on this machine = " << cores << std::endl;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        data[i] = rand() % 20;
    }

    #pragma omp parallel for reduction(+:global_sum)
    for (int i = 0; i < MAX; i++) {
        global_sum += data[i];
    }

    std::cout << "The final sum = " << global_sum << std::endl;

    return 0;
}
