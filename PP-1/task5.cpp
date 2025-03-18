#include <omp.h>
#include <iostream>
using namespace std;

int task5() {
    int upper_number;
    long long total_sum = 0;

    //cin >> upper_number;
    upper_number = 4;
    cout << upper_number << '\n';

    // use 2 threads for each half of range
#pragma omp parallel num_threads(2) reduction(+:total_sum)
    {
        int thread_id = omp_get_thread_num();
        long long partial_sum = 0;

        if (thread_id == 0) {
            for (int i = 1; i <= upper_number / 2; i++) {
                partial_sum += i;
            }
        } else if (thread_id == 1) {
            for (int i = upper_number / 2 + 1; i <= upper_number; i++) {
                partial_sum += i;
            }
        }

        total_sum += partial_sum;

#pragma omp critical
        {
            cout << "[" << thread_id << "]: Sum = " << partial_sum << endl;
        }
    }

    cout << "Sum = " << total_sum << endl;
    return 0;
}