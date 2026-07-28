#include <stdlib.h>
#include <string.h>

void solve(int row, int n, char **board, int *cols, int *diag1, int *diag2,
           char ***result, int *returnSize, int *returnColumnSizes) {

    if (row == n) {
        result[*returnSize] = (char **)malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = strdup(board[i]);
        }

        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        board[row][col] = 'Q';

        cols[col] = 1;
        diag1[row + col] = 1;
        diag2[row - col + n - 1] = 1;

        solve(row + 1, n, board, cols, diag1, diag2,
              result, returnSize, returnColumnSizes);

        board[row][col] = '.';

        cols[col] = 0;
        diag1[row + col] = 0;
        diag2[row - col + n - 1] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    int maxSolutions = 1;
    for (int i = 1; i <= n; i++)
        maxSolutions *= i;

    char ***result = (char ***)malloc(maxSolutions * sizeof(char **));

    *returnColumnSizes = (int *)malloc(maxSolutions * sizeof(int));

    char **board = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++)
            board[i][j] = '.';

        board[i][n] = '\0';
    }

    int *cols = calloc(n, sizeof(int));
    int *diag1 = calloc(2 * n, sizeof(int));
    int *diag2 = calloc(2 * n, sizeof(int));

    *returnSize = 0;

    solve(0, n, board, cols, diag1, diag2,
          result, returnSize, *returnColumnSizes);

    free(cols);
    free(diag1);
    free(diag2);

    for (int i = 0; i < n; i++)
        free(board[i]);

    free(board);

    return result;
}
