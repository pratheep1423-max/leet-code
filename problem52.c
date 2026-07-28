void backtrack(int row, int n, int *cols, int *diag1, int *diag2, int *count) {

    if (row == n) {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        cols[col] = 1;
        diag1[row + col] = 1;
        diag2[row - col + n - 1] = 1;

        backtrack(row + 1, n, cols, diag1, diag2, count);

        cols[col] = 0;
        diag1[row + col] = 0;
        diag2[row - col + n - 1] = 0;
    }
}

int totalNQueens(int n) {

    int count = 0;

    int *cols = (int *)calloc(n, sizeof(int));
    int *diag1 = (int *)calloc(2 * n, sizeof(int));
    int *diag2 = (int *)calloc(2 * n, sizeof(int));

    backtrack(0, n, cols, diag1, diag2, &count);

    free(cols);
    free(diag1);
    free(diag2);

    return count;
}
