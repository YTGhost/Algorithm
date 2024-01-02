class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                cnt++;
                if(cnt > res) {
                    res = cnt;
                }
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, sum = 0;
        for(auto num : nums)
        {
            if(num) sum++;
            else res = max(res, sum), sum = 0;
        }
        return max(res, sum);
    }
};

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