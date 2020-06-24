class Solution {
public:
    int ans;
    int diff = INT_MAX;
    int TwoSum(vector<int>& nums, int begin, int end, int target, int value){
        while(begin < end)
        {
            int sum = nums[begin] + nums[end];
            if(abs(target-sum) < diff){
                diff = abs(target-sum);
                ans = sum + value;
                if(diff == 0) return ans;
            } 
            if(sum > target){
                end--;
            }else{
                begin++;
            }
        }
        return 0;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int res = TwoSum(nums, i+1, size-1, target-nums[i], nums[i]);
            if(res) return res;
        }
        return ans;
    }
};