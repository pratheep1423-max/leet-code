#include <string.h>
#include <stdlib.h>

int* findSubstring(char* s, char** words, int wordsSize,
                   int* returnSize) {
    
    *returnSize = 0;

    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;

    int* result = malloc(sLen * sizeof(int));

    // Store the count of each word
    int* wordCount = calloc(wordsSize, sizeof(int));

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCount[j]++;
                wordCount[i] = -1;
                break;
            }
        }

        if (wordCount[i] == 0)
            wordCount[i] = 1;
    }

    // Try each possible offset
    for (int offset = 0; offset < wordLen; offset++) {

        int left = offset;
        int right = offset;
        int count = 0;

        int* used = calloc(wordsSize, sizeof(int));

        while (right + wordLen <= sLen) {

            char current[wordLen + 1];
            strncpy(current, s + right, wordLen);
            current[wordLen] = '\0';

            int index = -1;

            // Find the word index
            for (int i = 0; i < wordsSize; i++) {
                if (strcmp(current, words[i]) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1 || wordCount[index] == -1) {
                // Reset window
                memset(used, 0, wordsSize * sizeof(int));
                count = 0;
                left = right + wordLen;
            }
            else {
                used[index]++;
                count++;

                // Too many occurrences of this word
                while (used[index] > wordCount[index]) {
                    char leftWord[wordLen + 1];

                    strncpy(leftWord, s + left, wordLen);
                    leftWord[wordLen] = '\0';

                    for (int i = 0; i < wordsSize; i++) {
                        if (strcmp(leftWord, words[i]) == 0) {
                            used[i]--;
                            break;
                        }
                    }

                    left += wordLen;
                    count--;
                }

                // All words matched
                if (count == wordsSize) {
                    result[(*returnSize)++] = left;

                    char leftWord[wordLen + 1];

                    strncpy(leftWord, s + left, wordLen);
                    leftWord[wordLen] = '\0';

                    for (int i = 0; i < wordsSize; i++) {
                        if (strcmp(leftWord, words[i]) == 0) {
                            used[i]--;
                            break;
                        }
                    }

                    left += wordLen;
                    count--;
                }
            }

            right += wordLen;
        }

        free(used);
    }

    free(wordCount);
    return result;
}
