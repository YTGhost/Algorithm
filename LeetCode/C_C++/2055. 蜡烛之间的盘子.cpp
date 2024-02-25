class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> res, presum(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') sum++;
            presum[i] = sum;
        }
        vector<int> left(n);
        for(int i = 0, l = -1; i < n; i++) {
            if(s[i] == '|') l = i;
            left[i] = l;
        }
        vector<int> right(n);
        for(int i = n - 1, r = -1; i >= 0; i--) {
            if(s[i] == '|') r = i;
            right[i] = r;
        }
        for(auto item : queries) {
            int x = right[item[0]], y = left[item[1]];
            res.push_back(x == -1 || y == -1 || x >= y ? 0 : presum[y] - presum[x]);
        }
        return res;
    }
};