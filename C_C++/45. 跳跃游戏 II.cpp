class Solution {
public:
    int jump(vector<int>& nums) {
       int maxPoint = 0;
       int end = 0;
       int ans = 0;
       for(int i = 0; i < nums.size() - 1; i++)
       {
           maxPoint = max(maxPoint, nums[i] + i);
           if(i == end)
           {
               ans++;
               end = maxPoint;
               if(maxPoint >= nums.size() - 1) return ans;
           }
       }
       return ans;
    }
};