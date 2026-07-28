#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int index = 0;

    for (int i = 0; i < intervalsSize; i++) {

        if (index == 0 || result[index - 1][1] < intervals[i][0]) {
            result[index] = (int *)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            index++;
        }
        else {
            if (intervals[i][1] > result[index - 1][1])
                result[index - 1][1] = intervals[i][1];
        }
    }

    for (int i = 0; i < index; i++)
        (*returnColumnSizes)[i] = 2;

    *returnSize = index;

    return result;
}
