#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int* number1, int* number2);

int main(int argc, char *argv[]) {
    int SIZE = 1 << 8;
    int B[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        B[i] = rand() % SIZE;
    }

    int X = SIZE;
    int i = 0, j = 0;
    int first;
    double start, stop;
    start = omp_get_wtime();

    for (i = 0; i < X - 1; i++)
    {
        first = i % 2;
        for (j = first; j < X - 1; j += 1) 
        {
            if (B[j] > B[j + 1])
            {
                swap(&B[j], &B[j + 1]);
            }
        }
    }
    stop = omp_get_wtime();

    for (i = 0; i < X; i++)
    {
        printf("%d ", B[i]);
    }

    printf("\nTime elapsed: %f\n", (stop - start));
}

void swap(int* number1, int* number2) 
{
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}