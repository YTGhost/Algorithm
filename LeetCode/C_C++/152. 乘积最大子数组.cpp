class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxF(nums), minF(nums);
        for(int i = 1; i < n; i++) {
            maxF[i] = max({nums[i], maxF[i - 1] * nums[i], minF[i - 1] * nums[i]});
            minF[i] = min({nums[i], maxF[i - 1] * nums[i], minF[i - 1] * nums[i]});
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tempMax = 1;
        int tempMin = 1;
        int Max = INT_MIN;
        for(auto it : nums)
        {
            if(it < 0){
                int temp = tempMax;
                tempMax = tempMin;
                tempMin = temp;
            }
            tempMax = max(tempMax*it, it);
            tempMin = min(tempMin*it, it);
            Max = max(tempMax, Max);
        }
        return Max;
    }
};