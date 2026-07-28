#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k) {

    int fact[10];
    fact[0] = 1;

    for (int i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i;

    // Store available numbers
    int nums[10];

    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    k--;   // Convert to 0-based index

    char *result = (char *)malloc(n + 1);

    int index = 0;

    for (int i = n; i >= 1; i--) {

        int block = fact[i - 1];

        int pos = k / block;

        result[index++] = nums[pos] + '0';

        // Remove used number
        for (int j = pos; j < i - 1; j++)
            nums[j] = nums[j + 1];

        k %= block;
    }

    result[index] = '\0';

    return result;
}
