/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int top = 0;

    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];

        while (top > 0 && asteroids[top - 1] > 0 && current < 0) {
            if (asteroids[top - 1] < -current) {
                top--;
                continue;
            }
            
            if (asteroids[top - 1] == -current) {
                top--;
            }

            current = 0;
            break;
        }

        if (current != 0) {
            asteroids[top] = current;
            top++;
        }
    }

    *returnSize = top;
    return asteroids;
}