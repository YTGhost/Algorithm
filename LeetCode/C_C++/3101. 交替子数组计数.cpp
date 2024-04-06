class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            i && nums[i] != nums[i - 1] ? cnt++ : cnt = 1;
            res += cnt;
        }
        return res;
    }
};