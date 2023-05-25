#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;

    int *a = new int[size];
    int *b = new int[size];
    int *c = new int[size];

    printf("\n First Vector:\t");
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 1000;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n Second Vector:\t");
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        b[i] = rand() % 1000;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", b[i]);
    }

    printf("\n Parallel-Vector Addition:(a,b,c)\t");
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        c[i] = a[i] + b[i];
    }

    for (int i = 0; i < size; i++)
    {
        printf("\n%d\t%d\t%d", a[i], b[i], c[i]);
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
