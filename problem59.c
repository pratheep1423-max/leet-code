#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    *returnSize = n;

    *returnColumnSizes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = n;


    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int value = 1;

    while (top <= bottom && left <= right) {

        // Fill top row
        for (int i = left; i <= right; i++)
            matrix[top][i] = value++;
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = value++;
        right--;

        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = value++;
            bottom--;
        }

        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = value++;
            left++;
        }
    }

    return matrix;
}
