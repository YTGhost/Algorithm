class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int pre = 0, res = 0;
        for(int i = 0; i < n; i++) {
            pre += nums[i];
            if(m.count(pre - k)) {
                res += m[pre - k];
            }
            m[pre]++;
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int pre = 0, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];
            if(m.find(pre-k) != m.end()) count += m[pre-k];
            m[pre]++;
        }
        return count;
    }
};