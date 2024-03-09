class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0LL;
        int n = nums.size();
        for(int &num : nums) {
            if(num >= 0) {
                sum += num;
            } else {
                num = -num;
            }
        }
        ranges::sort(nums);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>q;
        q.push({0, 0});
        while(--k) {
            auto [s, idx] = q.top();
            q.pop();
            if(idx < n) {
                q.push({s + nums[idx], idx + 1});
                if(idx) {
                    q.push({s + nums[idx] - nums[idx - 1], idx + 1});
                }
            }
        }
        return sum - q.top().first;
    }
};