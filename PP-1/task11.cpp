#include <iostream>
#include <omp.h>
using namespace std;

int task11() {
    int N = 2, threads_count = 3;

    cout << threads_count << endl << N << endl;
    /*cout << "Enter the number of threads: ";
    cin >> threads_count;
    cout << "Enter the value of N: ";
    cin >> N;*/

    long long sum = 0;

#pragma omp parallel for num_threads(threads_count)
    for (int i = 1; i <= N; ++i) {
#pragma omp atomic
        sum += i;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}