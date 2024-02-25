class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            if(__builtin_popcount(i) == k) {
                res += nums[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    int getCnt(int t) {
        int res = 0;
        while(t) {
            res += t & 1;
            t >>= 1;
        }
        return res;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(getCnt(i) == k) {
                res += nums[i];
            }
        }
        return res;
    }
};