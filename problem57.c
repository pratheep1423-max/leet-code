#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColumnSizes) {

    int **result = (int **)malloc((intervalsSize + 1) * sizeof(int *));
    *returnColumnSizes = (int *)malloc((intervalsSize + 1) * sizeof(int));

    int index = 0;
    int i = 0;

    // Add intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[index] = (int *)malloc(2 * sizeof(int));
        result[index][0] = intervals[i][0];
        result[index][1] = intervals[i][1];
        index++;
        i++;
    }

    // Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0])
            newInterval[0] = intervals[i][0];

        if (intervals[i][1] > newInterval[1])
            newInterval[1] = intervals[i][1];

        i++;
    }

    // Add merged interval
    result[index] = (int *)malloc(2 * sizeof(int));
    result[index][0] = newInterval[0];
    result[index][1] = newInterval[1];
    index++;

    // Add remaining intervals
    while (i < intervalsSize) {
        result[index] = (int *)malloc(2 * sizeof(int));
        result[index][0] = intervals[i][0];
        result[index][1] = intervals[i][1];
        index++;
        i++;
    }

    for (int j = 0; j < index; j++)
        (*returnColumnSizes)[j] = 2;

    *returnSize = index;

    return result;
}
