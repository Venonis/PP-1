#include <omp.h>
#include <iostream>
using namespace std;

int task3() {
    uint16_t thread_nums;
    //cin >> thread_nums;
    thread_nums = 3;
    cout << thread_nums << '\n';

    omp_set_num_threads(thread_nums);

#pragma omp parallel
    {
#pragma omp critical
        {
            int thread_id = omp_get_thread_num();
            if (thread_id % 2 == 0)
                cout << "I am " << thread_id << " from " << thread_nums << " threads" << endl;
        }
    }
    return 0;
}