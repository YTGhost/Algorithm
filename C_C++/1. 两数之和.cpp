// LeetCode究极班打卡
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            int r = target - nums[i];
            if(map.count(r)) return {i, map[r]};
            map[nums[i]] = i; 
        }
        return {};
    }
};

// 2020/10/03每日一题
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            auto temp = map.find(target-nums[i]);
            if(temp != map.end()) return {i, map[target-nums[i]]};
            map[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target){
                    ans[0] = i, ans[1] = j;
                    cout << nums[i] << nums[j];
                    break;
                }
            }
        return ans;
    }
};