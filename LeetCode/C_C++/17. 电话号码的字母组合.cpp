class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if(n == 0) return res;
        vector<vector<string>> combinations(10);
        string str = "";
        combinations[2] = {"a", "b", "c"};
        combinations[3] = {"d", "e", "f"};
        combinations[4] = {"g", "h", "i"};
        combinations[5] = {"j", "k", "l"};
        combinations[6] = {"m", "n", "o"};
        combinations[7] = {"p", "q", "r", "s"};
        combinations[8] = {"t", "u", "v"};
        combinations[9] = {"w", "x", "y", "z"};
        function<void(int idx)> dfs = [&](int idx) {
            if(idx == n) {
                res.push_back(str);
                return;
            }
            for(auto item : combinations[digits[idx] - '0']) {
                str += item;
                dfs(idx + 1);
                str.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};

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