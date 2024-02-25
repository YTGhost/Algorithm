class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int candy = 1;
        while(candies != 0){
            for(int i = 0; i < num_people; i++)
            {
                if(candy >= candies)
                {
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
                ans[i] += candy;
                candies -= candy;
                candy++;
            }
        }
        return ans;
    }
};