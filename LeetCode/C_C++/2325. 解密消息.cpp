class Solution {
public:
    string decodeMessage(string key, string message) {
        int cnt = 0;
        vector<int> hash(26, -1);
        for(auto c : key) {
            if(c == ' ') continue;
            if(hash[c - 'a'] == -1) {
                hash[c - 'a'] = cnt++;
            }
        }
        string res;
        for(auto c : message) {
            if(c == ' ') {
                res += ' ';
                continue;
            }
            res += 'a' + hash[c - 'a'];
        }
        return res;
    }
};