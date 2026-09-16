/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count1 > 0 && nums[i] == candidate1) {
            count1++;
        }
        else if (count2 > 0 && nums[i] == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1)
            count1++;

        if (nums[i] == candidate2)
            count2++;
    }

    *returnSize = 0;

    int *result = malloc(2 * sizeof(int));

    if (count1 > numsSize / 3)
        result[(*returnSize)++] = candidate1;

    if (candidate2 != candidate1 && count2 > numsSize / 3)
        result[(*returnSize)++] = candidate2;

    return result;
}