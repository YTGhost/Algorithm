class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            int cnt = stk.size();
            if(stk.empty() || cnt % 2 == 0) {
                stk.push(nums[i]);
            } else if(nums[i] == stk.top()) {
                stk.pop();
                stk.push(nums[i]);
            } else {
                stk.push(nums[i]);
            }
        }
        return n - (stk.size() % 2 == 0 ? stk.size() : stk.size() - 1);
    }
};