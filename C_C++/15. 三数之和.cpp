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