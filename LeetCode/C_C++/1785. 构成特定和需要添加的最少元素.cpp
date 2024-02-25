class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        long long sub = abs(goal - sum);
        return (sub + limit - 1) / limit;
    }
};