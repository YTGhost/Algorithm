class Solution {
public:
    unordered_map<int, int> hash;
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                hash[nums[i] * nums[j]]++;
            }
        }
        for(auto& [_, v] : hash) {
            if(v > 1) {
                res += v * (v - 1) * 4;
            }
        }
        return res;
    }
};