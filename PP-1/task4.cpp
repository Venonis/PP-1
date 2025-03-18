#include <omp.h>
#include <iostream>
using namespace std;

int task4() {
    uint16_t thread_nums;
    //cin >> thread_nums;
    thread_nums = 3;
    cout << thread_nums << '\n';

    omp_set_num_threads(thread_nums);

    int thread_id;
    // make local copy of thread_id for each thread
#pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
#pragma omp critical
        {
            cout << "I am " << thread_id << " from " << thread_nums << " threads" << endl;
        }
    }
    return 0;
}