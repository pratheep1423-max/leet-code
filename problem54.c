int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int *result = (int *)malloc(rows * cols * sizeof(int));

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int k = 0;

    while (top <= bottom && left <= right) {

        // Traverse top row
        for (int i = left; i <= right; i++)
            result[k++] = matrix[top][i];
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[k++] = matrix[bottom][i];
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;

    return result;
}
