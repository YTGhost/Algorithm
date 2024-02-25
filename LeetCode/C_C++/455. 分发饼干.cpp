class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child = 0, cookie = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(child < g.size() && cookie < s.size()) {
            if(g[child] <= s[cookie]) child++;
            cookie++;
        }
        return child;
    }
};