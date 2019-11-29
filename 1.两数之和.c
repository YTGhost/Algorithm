/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int j, k;
    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (j = 0; j < numsSize; j++)
    {
        for (k = j + 1; k < numsSize; k++)
        {
            if (nums[j] + nums[k] == target)
            {
                result[0] = j;
                result[1] = k;
                return result;
            }
        }
    }
    return result;
}
