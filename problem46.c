#include <stdlib.h>
#include <string.h>

void backtrack(int* nums, int numsSize, int* used, int* path, int depth,
               int** result, int* returnSize) {
    if (depth == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], path, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;

        used[i] = 1;
        path[depth] = nums[i];
        backtrack(nums, numsSize, used, path, depth + 1, result, returnSize);
        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerm = 1;
    for (int i = 2; i <= numsSize; i++)
        maxPerm *= i;

    int** result = (int**)malloc(maxPerm * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerm * sizeof(int));

    int* used = (int*)calloc(numsSize, sizeof(int));
    int* path = (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, used, path, 0, result, returnSize);

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(used);
    free(path);

    return result;
}
