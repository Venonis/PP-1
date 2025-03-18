#include <iostream>
#include <omp.h>
using namespace std;

int task10() {
    int threads_count;

    cout << "Enter the number of threads: ";
    cin >> threads_count;
    //threads_count = 3;
    //cout << threads_count << endl;

#pragma omp parallel num_threads(threads_count)
    {
#pragma omp sections
        {
#pragma omp section
            {
                int thread_id = omp_get_thread_num();
#pragma omp critical
                {
                    cout << "[" << thread_id << "]: came in section 1" << endl;
                }
            }

#pragma omp section
            {
                int thread_id = omp_get_thread_num();
#pragma omp critical
                {
                    cout << "[" << thread_id << "]: came in section 2" << endl;
                }
            }

#pragma omp section
            {
                int thread_id = omp_get_thread_num();
#pragma omp critical
                {
                    cout << "[" << thread_id << "]: came in section 3" << endl;
                }
            }
        }

//        wait all
#pragma omp barrier
        {
            int thread_id = omp_get_thread_num();
#pragma omp critical
            {
                cout << "[" << thread_id << "]: parallel region" << endl;
            }
        }
    }

    return 0;
}
