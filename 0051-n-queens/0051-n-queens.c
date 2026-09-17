/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isSafe(int row, int col, int n, int *board) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col)
            return false;

        if (abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

void solve(int row, int n, int *board, char ***result, int *returnSize, int *returnColumnSizes) {
    if (row == n) {
        result[*returnSize] = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = malloc((n + 1) * sizeof(char));

            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    result[*returnSize][i][j] = 'Q';
                else
                    result[*returnSize][i][j] = '.';
            }

            result[*returnSize][i][n] = '\0';
        }

        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, board)) {
            board[row] = col;

            solve(row + 1, n, board, result,
                  returnSize, returnColumnSizes);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int maxSolutions = 10000;

    char ***result = malloc(maxSolutions * sizeof(char**));
    *returnColumnSizes = malloc(maxSolutions * sizeof(int));

    int *board = malloc(n * sizeof(int));

    *returnSize = 0;

    solve(0, n, board, result,
          returnSize, *returnColumnSizes);

    free(board);

    return result;
}