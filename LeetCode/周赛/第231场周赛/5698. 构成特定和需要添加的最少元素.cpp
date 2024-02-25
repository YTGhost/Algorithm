class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n = nums.size();
        long long sum = goal;
        for(int i = 0; i < n; i++)
            sum -= nums[i];
        sum = abs(sum);
        return (sum + limit - 1) / limit;
    }
};