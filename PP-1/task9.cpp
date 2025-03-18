#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int task9() {
    int matrix_size;
    int threads_count;

    matrix_size = 2;
    cout << matrix_size << endl;
    //cout << "Enter the size of the matrices (matrix_size x matrix_size): ";
    //cin >> matrix_size;

    threads_count = 3;
    cout << threads_count << endl;
    //cout << "Enter the number of threads: ";
    //cin >> threads_count;

    vector<vector<int>> A(matrix_size, vector<int>(matrix_size));
    vector<vector<int>> B(matrix_size, vector<int>(matrix_size));
    vector<vector<int>> C(matrix_size, vector<int>(matrix_size, 0));

    A = {
        {1,3},
        {4,8}
    };
    B = {
        {5,4},
        {3,0}
    };

    cout << "Enter first matrix: \n";
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            //cin >> A[i][j];
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Enter second matrix: \n";
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            //cin >> B[i][j];
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

#pragma omp parallel for num_threads(threads_count) collapse(2)
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            for (int k = 0; k < matrix_size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult Matrix:\n";
    for (const auto& row : C) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
