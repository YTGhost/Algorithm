class Solution {
public:
    int f[100];
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        for(auto dominoe : dominoes)
        {
            int sum, a = dominoe[0], b = dominoe[1];
            sum = a < b ? a * 10 + b : b * 10 + a;
            res += f[sum]++;
        }
        return res;
    }
};