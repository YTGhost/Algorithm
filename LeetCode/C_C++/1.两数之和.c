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