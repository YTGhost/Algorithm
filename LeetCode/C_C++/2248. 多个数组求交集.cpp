class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                m[nums[i][j]]++;
            }
        }

        for(auto &[num, cnt] : m) {
            if(cnt == n) {
                res.push_back(num);
            }
        }
        return res;
    }
};