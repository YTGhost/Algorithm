class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        function<void(int)> twoSum = [&](int idx) {
            int l = idx + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[idx];
                if(sum == 0) {
                    res.push_back({nums[idx], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                    while(l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if(sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        };
        for(int i = 0; i < n - 2; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            // 优化
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if(nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
            twoSum(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        function<void(int)> twoSum = [&](int idx) {
            int l = idx + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[idx];
                if(sum == 0) {
                    res.push_back({nums[idx], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                    while(l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if(sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        };
        for(int i = 0; i < n - 2; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            twoSum(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    void towSum(vector<int>& nums, int begin, int end, int target, int value){
        while(begin < end)
        {
            int sum = nums[begin] + nums[end];
            if(sum == target){
                ans.push_back(vector<int>{value, nums[begin], nums[end]});
                while(begin < end && nums[begin] == nums[begin+1]){
                    begin++;
                }
                begin++;
                while(begin < end && nums[end] == nums[end-1]){
                    end--;
                }
                end--;
            }else if(sum > target){
                end--;
            }else{
                begin++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            towSum(nums, i+1, size-1, -nums[i], nums[i]);
        }
        return ans;
    }
};