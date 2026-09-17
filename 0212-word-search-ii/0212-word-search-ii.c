/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TrieNode {
    struct TrieNode *child[26];
    char *word;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = malloc(sizeof(TrieNode));

    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;

    node->word = NULL;

    return node;
}

void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->child[index] == NULL)
            curr->child[index] = createNode();

        curr = curr->child[index];
    }

    curr->word = word;
}

void dfs(char **board, int row, int col,
         int rows, int cols, TrieNode *node,
         char **result, int *returnSize) {

    if (row < 0 || row >= rows ||
        col < 0 || col >= cols ||
        board[row][col] == '#')
        return;

    char c = board[row][col];
    TrieNode *next = node->child[c - 'a'];

    if (next == NULL)
        return;

    if (next->word != NULL) {
        result[*returnSize] = next->word;
        (*returnSize)++;

        next->word = NULL;
    }

    board[row][col] = '#';

    dfs(board, row + 1, col, rows, cols, next, result, returnSize);
    dfs(board, row - 1, col, rows, cols, next, result, returnSize);
    dfs(board, row, col + 1, rows, cols, next, result, returnSize);
    dfs(board, row, col - 1, rows, cols, next, result, returnSize);

    board[row][col] = c;
}

char** findWords(char** board, int boardSize,
                 int* boardColSize, char** words,
                 int wordsSize, int* returnSize) {

    TrieNode *root = createNode();

    for (int i = 0; i < wordsSize; i++)
        insert(root, words[i]);

    char **result = malloc(wordsSize * sizeof(char*));
    *returnSize = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {

            dfs(board, i, j,
                boardSize, boardColSize[0],
                root, result, returnSize);
        }
    }

    return result;
}