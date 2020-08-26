class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.size()) return res;
        unordered_map<char, string> map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string path;
        dfs(res, digits, map, 0, path);
        return res;
    }

    void dfs(vector<string>& res, string& digits, unordered_map<char, string>& map, int index, string& path) {
        if(index == digits.size()) {
            res.push_back(path);
            return;
        }
        for(auto item : map[digits[index]])
        {
            path.push_back(item);
            dfs(res, digits, map, index+1, path);
            path.pop_back();
        }
    }
};