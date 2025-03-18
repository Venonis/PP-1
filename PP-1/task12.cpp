#include <iostream>
#include <iomanip>
#include <omp.h>
using namespace std;

int task12() {
    long long num_steps = 1000000;
    int num_threads = 4;
    double step;

    cout << num_steps << endl << num_threads << endl;
    /*cout << "Enter the number of steps: ";
    cin >> num_steps;
    cout << "Enter the number of threads: ";
    cin >> num_threads;*/

    double pi = 0.0;
    step = 1.0 / num_steps;

#pragma omp parallel num_threads(num_threads)
    {
        double sum_threadlocal = 0.0;
        int thread_id = omp_get_thread_num();

#pragma omp for
        for (long long i = 0; i < num_steps; i++) {
            double x = (i + 0.5) * step;
            sum_threadlocal += 4.0 / (1.0 + x * x);
        }

#pragma omp critical
        {
            pi += sum_threadlocal * step;
        }
    }

    cout << fixed << setprecision(15);
    cout << "Computed value of pi: " << pi << endl;

    return 0;
}
