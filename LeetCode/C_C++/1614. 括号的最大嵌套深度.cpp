class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt = 0;
        for(auto c : s) {
            if(c == '(') {
                cnt++;
                res = max(res, cnt);
            } else if(c == ')') {
                cnt--;
            }
        }
        return res;
    }
};