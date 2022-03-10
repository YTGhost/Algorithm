class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int idx = 0, n = nums.size();
        for(; idx < k; idx++) {
            q.push(nums[idx]);
        }
        for(; idx < n; idx++) {
            if(nums[idx] > q.top()) {
                q.pop();
                q.push(nums[idx]);
            }
        }
        return q.top();
    }
};