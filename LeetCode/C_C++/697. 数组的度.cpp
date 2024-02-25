class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++)
        {
            if(m.count(nums[i])) {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
            } else {
                m[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for(auto &[_, vec] : m)
        {
            if(vec[0] > maxNum) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if(vec[0] == maxNum) {
                int len = vec[2] - vec[1] + 1;
                if(minLen > len) {
                    minLen = len;
                }
            }
        }
        return minLen;
    }
};