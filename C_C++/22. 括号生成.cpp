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