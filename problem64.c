int minPathSum(int** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int *dp = (int *)malloc(n * sizeof(int));

    // Initialize first row
    dp[0] = grid[0][0];

    for (int j = 1; j < n; j++)
        dp[j] = dp[j - 1] + grid[0][j];

    // Fill remaining rows
    for (int i = 1; i < m; i++) {

        dp[0] += grid[i][0];

        for (int j = 1; j < n; j++) {

            if (dp[j] < dp[j - 1])
                dp[j] = dp[j] + grid[i][j];
            else
                dp[j] = dp[j - 1] + grid[i][j];
        }
    }

    int result = dp[n - 1];

    free(dp);

    return result;
}
