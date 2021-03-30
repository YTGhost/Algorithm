class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++)
        {
            temp.clear();
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j)) {
                    if(j && (i >> (j-1) & 1) == 0 && nums[j] == nums[j-1]) {
                        flag = false;
                        break;
                    }
                    temp.emplace_back(nums[j]);
                }
            }
            if(flag) res.emplace_back(temp);
        }
        return res;
    }
};