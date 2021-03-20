class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for(auto c : coins)
        {
            if(c > sum + 1) return sum + 1;
            sum += c;
        }
        return sum + 1;
    }
};