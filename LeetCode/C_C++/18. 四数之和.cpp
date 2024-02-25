class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for(int i = 0; i < length - 3; i++)
        {
            if(i && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[length-1] + nums[length-2] + nums[length-3] < target) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            for(int j = i+1; j < length - 2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[length-1] + nums[length-2] < target) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                int left = j+1, right = length-1, temp = target - nums[i] - nums[j];
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    if(sum == temp) {
                        vector<int> t {nums[i], nums[j], nums[left], nums[right]};
                        res.emplace_back(t);
                        while(left < right && nums[left] == nums[left+1]) left++;
                        left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        right--;
                    } else if (sum < temp) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};