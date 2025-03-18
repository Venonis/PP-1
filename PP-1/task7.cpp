#include <omp.h>
#include <iostream>
using namespace std;

int task7() {
    int upper_number;
    int threads_count;
    long long total_sum = 0;

    cin >> threads_count;
    cin >> upper_number;

#pragma omp parallel for num_threads(threads_count) schedule(guided,2) reduction(+:total_sum)
    for (int i = 1; i <= upper_number; i++) {
        int thread_id = omp_get_thread_num();
#pragma omp critical
        {
            cout << "[" << thread_id << "]: calculation of the iteration number " << i << endl;
        }

        total_sum += i;
    }

    cout << "Total sum = " << total_sum << endl;
}