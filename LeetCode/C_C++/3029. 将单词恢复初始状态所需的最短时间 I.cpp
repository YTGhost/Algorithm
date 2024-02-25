class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        function<bool(string, string)> isPrefix = [&](const string& prefix, const string& str) {
            if (prefix.size() > str.size()) return false;
            return str.substr(0, prefix.size()) == prefix;
        };
        int res = 1, maxRes = (n + k - 1) / k;
        while(res < maxRes) {
            int l = k * res;
            if(l < n) {
                string t = word.substr(l, n - l);
                if(isPrefix(t, word)) {
                    return res;
                }
            }
            res++;
        }
        return res;
    }
};