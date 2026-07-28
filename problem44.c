#include <stdbool.h>

bool isMatch(char *s, char *p) {
    int i = 0, j = 0;
    int star = -1, match = 0;

    while (s[i]) {
        if (p[j] == '?' || p[j] == s[i]) {
            i++;
            j++;
        } 
        else if (p[j] == '*') {
            star = j++;
            match = i;
        } 
        else if (star != -1) {
            j = star + 1;
            i = ++match;
        } 
        else {
            return false;
        }
    }

    while (p[j] == '*')
        j++;

    return p[j] == '\0';
}
