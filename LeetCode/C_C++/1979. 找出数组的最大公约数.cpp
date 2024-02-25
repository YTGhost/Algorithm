class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxV = 0, minV = 1001;
        for(auto num : nums) {
            maxV = max(maxV, num);
            minV = min(minV, num);
        }
        return gcd(maxV, minV);
    }
};