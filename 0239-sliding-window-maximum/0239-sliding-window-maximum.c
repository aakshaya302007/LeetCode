/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = malloc((numsSize - k + 1) * sizeof(int));
    int *deque = malloc(numsSize * sizeof(int));

    int front = 0;
    int back = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {

        while (front < back && deque[front] <= i - k)
            front++;

        while (front < back && nums[deque[back - 1]] <= nums[i])
            back--;

        deque[back++] = i;

        if (i >= k - 1) {
            result[count++] = nums[deque[front]];
        }
    }

    *returnSize = count;

    free(deque);

    return result;
}