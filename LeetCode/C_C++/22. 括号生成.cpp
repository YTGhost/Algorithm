class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        function<void(int, int)> dfs = [&](int left, int right) {
            if(left + right == 2 * n) {
                res.push_back(str);
                return;
            }
            if(left < n) {
                str += "(";
                dfs(left + 1, right);
                str.pop_back();
            }
            if(right < left) {
                str += ")";
                dfs(left, right + 1);
                str.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
};

class Solution {
public:
    vector<string> s;
    vector<string> generateParenthesis(int n) {
        string t = "";
        dfs(n, 0, t);
        return s;
    }

    void dfs(int n, int m, string t){
        if(n == 0 && m == 0){
            s.push_back(t);
            return;
        }
        if(m == 0) dfs(n-1, m+1, t+'(');
        else if(n != 0){
            dfs(n-1, m+1, t+'(');
            dfs(n, m-1, t+')');
        }else{
            dfs(n, m-1, t+')');
        }
    }
};