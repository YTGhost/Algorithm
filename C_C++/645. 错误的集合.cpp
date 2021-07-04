class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for(auto num : nums) {
            hash[num]++;
        }
        int a, b;
        for(int i = 1; i <= n; i++) {
            if(hash[i] == 2) a = i;
            if(hash[i] == 0) b = i;
        }
        return {a, b};
    }
};