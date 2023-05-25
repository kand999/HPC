#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int mat[m][n], vec[n], out[m];

    // matrix input
    cout << "Input Matrix:" << endl;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << "Enter element at position (" << row << ", " << col << "): ";
            cin >> mat[row][col];
        }
    }

    // display matrix
    cout << "Input Matrix:" << endl;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << "\t" << mat[row][col];
        }
        cout << endl;
    }

    // column vector input
    cout << "Input Col-Vector:" << endl;
    for (int row = 0; row < n; row++)
    {
        cout << "Enter element at position (" << row << ", 0): ";
        cin >> vec[row];
    }

    // display vector
    cout << "Input Col-Vector:" << endl;
    for (int row = 0; row < n; row++)
    {
        cout << vec[row] << endl;
    }

    // matrix-vector multiplication
    #pragma omp parallel
    {
        #pragma omp parallel for
        for (int row = 0; row < m; row++)
        {
            out[row] = 0;
            for (int col = 0; col < n; col++)
            {
                out[row] += mat[row][col] * vec[col];
            }
        }
    }

    // display resultant vector
    cout << "Resultant Col-Vector:" << endl;
    for (int row = 0; row < m; row++)
    {
        cout << "\nvec[" << row << "]: " << out[row] << endl;
    }

    return 0;
}
