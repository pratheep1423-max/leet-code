#include <stdlib.h>
#include <string.h>

#define SIZE 10000

typedef struct Node {
    char key[101];
    char **words;
    int count;
    int capacity;
    struct Node *next;
} Node;

unsigned int hash(char *str) {
    unsigned int h = 0;
    while (*str)
        h = h * 31 + *str++;
    return h % SIZE;
}

int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    Node *table[SIZE] = {0};

    for (int i = 0; i < strsSize; i++) {
        char temp[101];
        strcpy(temp, strs[i]);

        qsort(temp, strlen(temp), sizeof(char), cmp);

        unsigned int index = hash(temp);

        Node *cur = table[index];

        while (cur) {
            if (strcmp(cur->key, temp) == 0)
                break;
            cur = cur->next;
        }

        if (!cur) {
            cur = (Node *)malloc(sizeof(Node));
            strcpy(cur->key, temp);
            cur->count = 0;
            cur->capacity = 10;
            cur->words = (char **)malloc(cur->capacity * sizeof(char *));
            cur->next = table[index];
            table[index] = cur;
        }

        if (cur->count == cur->capacity) {
            cur->capacity *= 2;
            cur->words = realloc(cur->words,
                                 cur->capacity * sizeof(char *));
        }

        cur->words[cur->count++] = strs[i];
    }


    int groups = 0;

    for (int i = 0; i < SIZE; i++) {
        Node *cur = table[i];
        while (cur) {
            groups++;
            cur = cur->next;
        }
    }

    char ***result = malloc(groups * sizeof(char **));
    *returnColumnSizes = malloc(groups * sizeof(int));

    int k = 0;

    for (int i = 0; i < SIZE; i++) {
        Node *cur = table[i];

        while (cur) {
            result[k] = cur->words;
            (*returnColumnSizes)[k] = cur->count;
            k++;
            cur = cur->next;
        }
    }

    *returnSize = groups;

    return result;
}
