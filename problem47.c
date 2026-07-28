#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int *nums, int numsSize, int *used, int *path, int depth,
               int **result, int *returnSize) {
    if (depth == numsSize) {
        result[*returnSize] = (int *)malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], path, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;

        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        path[depth] = nums[i];

        backtrack(nums, numsSize, used, path, depth + 1,
                  result, returnSize);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int maxPerm = 1;
    for (int i = 2; i <= numsSize; i++)
        maxPerm *= i;

    int **result = (int **)malloc(maxPerm * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxPerm * sizeof(int));

    int *used = (int *)calloc(numsSize, sizeof(int));
    int *path = (int *)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, used, path, 0, result, returnSize);

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(used);
    free(path);

    return result;
}
