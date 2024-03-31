class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        long long sum = 0;
        long long res = 0;
        for(int i = 0; i < k - 1; i++) {
            hash[nums[i]]++;
            sum += nums[i];
        }
        for(int i = k - 1; i < n; i++) {
            hash[nums[i]]++;
            sum += nums[i];
            if(hash.size() >= m) {
                res = max(res, sum);
            }
            int out = nums[i - k + 1];
            sum -= out;
            hash[out]--;
            if(hash[out] == 0) {
                hash.erase(out);
            }
        }
        return res;
    }
};