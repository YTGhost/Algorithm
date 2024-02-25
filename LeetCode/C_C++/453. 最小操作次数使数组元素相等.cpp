class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        int sum = 0;
        for(auto num : nums) {
            minNum = min(minNum, num);
            sum += num;
        }
        return sum - minNum * nums.size();
    }
};