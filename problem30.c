#include <string.h>
#include <stdlib.h>

int* findSubstring(char* s, char** words, int wordsSize,
                   int* returnSize) {
    
    *returnSize = 0;

    int wordLen = strlen(words[0]);
    int sLen = strlen(s);
    int totalLen = wordLen * wordsSize;

    int* result = malloc(sLen * sizeof(int));

    for (int i = 0; i <= sLen - totalLen; i++) {

        int* used = calloc(wordsSize, sizeof(int));
        int count = 0;
        int j = i;

        while (count < wordsSize) {

            int found = -1;

            // Check which word matches
            for (int k = 0; k < wordsSize; k++) {
                if (!used[k] &&
                    strncmp(s + j, words[k], wordLen) == 0) {
                    found = k;
                    break;
                }
            }

            if (found == -1)
                break;

            used[found] = 1;
            count++;
            j += wordLen;
        }

        // All words matched
        if (count == wordsSize) {
            result[(*returnSize)++] = i;
        }

        free(used);
    }

    return result;
}
