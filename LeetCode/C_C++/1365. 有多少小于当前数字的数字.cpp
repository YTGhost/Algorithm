class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> num(101, 0);
        int size = nums.size();
        for(int i = 0; i < size; i++)
            num[nums[i]]++;
        for(int i = 1; i < 101; i++)
            num[i] += num[i-1];
        vector<int> res;
        for(int i = 0; i < size; i++)
            res.emplace_back(nums[i] == 0 ? 0 : num[nums[i]-1]);
        return res;
    }
};