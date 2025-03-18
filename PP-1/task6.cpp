#include <omp.h>
#include <iostream>
using namespace std;

int task6() {
    int upper_number;
    int threads_count;
    long long total_sum = 0;

    /*cin >> threads_count;
    cin >> upper_number;*/
    threads_count = 3;
    upper_number = 2;
    cout << threads_count << endl << upper_number << endl;

#pragma omp parallel num_threads(threads_count) reduction(+:total_sum)
    {
        int thread_id = omp_get_thread_num();
        long long thread_sum = 0;

#pragma omp for
        for (int i = 1; i <= upper_number; i++) {
            thread_sum += i;
        }

        total_sum += thread_sum;

#pragma omp critical
        {
            cout << "[" << thread_id << "]: Sum = " << thread_sum << endl;
        }
    }

    cout << "Sum = " << total_sum << endl;
}