class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        if(length == 0) return 0;
        vector<int> candy(length, 1);
        int ans = 0;
        for(int i = 1; i < length; i++)
            if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1] + 1;
        
        ans += candy[length-1];
        for(int i = length-2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]) candy[i] = candy[i+1] + 1;
            ans += candy[i];
        }
        return ans;
    }
};