class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int count = 0;
        int sign = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0){
                if(sign == 1){
                    sign = 0;
                    maxNum = max(maxNum, count);
                    count = 0;
                }
            }else{
                if(sign == 0) sign = 1;
                count++;
            }
        }
        return count == 0 ? maxNum : max(maxNum, count);
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1) count++;
            else count = 0;
            maxNum = max(maxNum, count);
        }
        return maxNum;
    }
};