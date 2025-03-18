#include "task.h"
#include <omp.h>
#include <iostream>
using namespace std;

int task2() {
    omp_set_num_threads(4);
#pragma omp parallel
    {
        cout << "Hello world!" << "\n";
    }
    return 0;
}