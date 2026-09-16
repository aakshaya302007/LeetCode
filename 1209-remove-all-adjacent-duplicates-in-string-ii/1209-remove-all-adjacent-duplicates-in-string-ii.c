char* removeDuplicates(char* s, int k) {
    int n = strlen(s);
    int *count = malloc(n * sizeof(int));

    int top = 0;

    for (int i = 0; i < n; i++) {
        s[top] = s[i];

        if (top > 0 && s[top] == s[top - 1])
            count[top] = count[top - 1] + 1;
        else
            count[top] = 1;

        top++;

        if (count[top - 1] == k)
            top -= k;
    }

    s[top] = '\0';

    free(count);

    return s;
}