#include <iostream>
#include <iomanip>
#include <omp.h>
using namespace std;

int task8() {
    long long steps_count;
    //cin >> steps_count;
    steps_count = 1000000;
    cout << steps_count<<endl;

    int num_threads = 4;
    double pi = 0.0;
    double step = 1.0 / steps_count;

#pragma omp parallel for num_threads(num_threads) reduction(+:pi)
    for (long long i = 0; i < steps_count; i++) {
        double x = (i + 0.5) * step;
        pi += 4.0 / (1.0 + x * x);
    }

    pi *= step;

    cout << fixed << setprecision(15);
    cout << pi << endl;

    return 0;
}