class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        int mask = (1 << n) - 1;
        for (int x = 0; x < (1 << n); x++) {
            if ((x & (x >> 1)) == 0) {
                res.push_back(bitset<18>(x ^ mask).to_string().substr(18 - n));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string path = "";
        function<bool(string&)> check = [&](string &str) {
            for (int i = 0; i < str.length() - 1; i++) {
                if (str[i] != '1' && str[i + 1] != '1') {
                    return false;
                }
            }
            return true;
        };
        function<void()> dfs = [&]() {
            if (path.length() == n) {
                if (check(path)) {
                    res.push_back(path);
                }
                return;
            }
            path.push_back('0');
            dfs();
            path.pop_back();
            path.push_back('1');
            dfs();
            path.pop_back();
        };
        dfs();
        return res;
    }
};