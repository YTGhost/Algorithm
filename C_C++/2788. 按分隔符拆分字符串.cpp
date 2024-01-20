class Solution {
public:
    void handle(string &str, char separator, vector<string> &res) {
        int n = str.size();
        int l = 0, r = 0;
        while(r < n) {
            if(str[r] == separator) {
                if(r != l) {
                    res.push_back(str.substr(l, r - l));
                }
                l = r + 1;
            }
            r++;
        }
        if(l != n) {
            res.push_back(str.substr(l, r - l));
        }
    }
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(auto str : words) {
            handle(str, separator, res);
        }
        return res;
    }
};