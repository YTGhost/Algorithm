class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int idx1 = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int idx2 = lower_bound(nums.begin(), nums.end(), 0) - 1 - nums.begin();
        return max(n - idx1, idx2 + 1);
    }
};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        for(auto num : nums) {
            if(num > 0) cnt1++;
            else if(num < 0) cnt2++;
        }
        return max(cnt1, cnt2);
    }
};