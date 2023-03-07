#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>
#include<pthread.h>
#include<thread>

using namespace std;
#define MAX 1000000


int data[MAX];
long global_sum = 0;

int main(int argc, char *argv[])
{
    int cores = std::thread::hardware_concurrency();
    cout << "The number of cores on this machine = " << cores << endl;

    // srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        data[i] = rand() % 20;
    }

    #pragma omp parallel num_threads(cores) reduction(+:global_sum)
    {
        #pragma omp for
        for (int i = 0; i < MAX; i++)
        {
            global_sum += data[i];
        }
    }

    cout << "The final sum = " << global_sum << endl;
}
