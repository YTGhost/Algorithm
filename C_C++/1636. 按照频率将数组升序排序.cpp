class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if(m[a] != m[b]) {
                return m[a] < m[b];
            }
            return a > b;
        });
        return nums;
    }
};