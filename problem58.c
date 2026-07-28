int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;

    // Count last word length
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
