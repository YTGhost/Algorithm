class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        vector<bool> plan(candies.size());
        for(int i = 0; i < candies.size(); i++)
        {
            maxNum = max(maxNum, candies[i]);
        }
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxNum) plan[i] = true;
            else plan[i] = false;
        }
        return plan;
    }
};