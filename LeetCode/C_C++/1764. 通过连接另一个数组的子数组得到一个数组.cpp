class Solution {
public:
    bool check(vector<int>& nums, int k, vector<int>& group) {
        if(k + group.size() > nums.size()) {
            return false;
        }
        for(int i = 0; i < group.size(); i++) {
            if(group[i] != nums[k + i]) {
                return false;
            }
        }
        return true;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, n = groups.size(), m = nums.size();
        for(int k = 0; k < m && i < n;) {
            if(check(nums, k, groups[i])) {
                k += groups[i].size();
                i++;
            } else {
                k++;
            }
        }
        return i == n;
    }
};