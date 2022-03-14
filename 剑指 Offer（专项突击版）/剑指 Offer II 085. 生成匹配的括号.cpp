class Solution {
public:
    vector<string> res;
    void dfs(string str, int left, int right) {
        if(!left && !right) {
            res.push_back(str);
            return;
        }
        if(left == right) {
            dfs(str + "(", left - 1, right);
        } else if(left < right) {
            if(left > 0) {
                dfs(str + "(", left - 1, right);
            }
            dfs(str + ")", left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};