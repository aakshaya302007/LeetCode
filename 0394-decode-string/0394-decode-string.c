#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int n = strlen(s);

    int *numStack = malloc(n * sizeof(int));
    char **strStack = malloc(n * sizeof(char*));

    int top = -1;
    int num = 0;

    char *current = malloc(1);
    current[0] = '\0';

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '[') {
            top++;
            numStack[top] = num;
            strStack[top] = current;

            num = 0;

            current = malloc(1);
            current[0] = '\0';
        }

        else if (s[i] == ']') {
            int repeat = numStack[top];
            char *previous = strStack[top];

            int len1 = strlen(previous);
            int len2 = strlen(current);

            char *temp = malloc(len1 + (len2 * repeat) + 1);

            strcpy(temp, previous);

            for (int j = 0; j < repeat; j++)
                strcat(temp, current);

            free(previous);
            free(current);

            current = temp;
            top--;
        }

        else {
            int len = strlen(current);

            current = realloc(current, len + 2);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    free(numStack);
    free(strStack);

    return current;
}