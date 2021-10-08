class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> res;
        if(s.length() <= 10) return res;
        for(int i = 0; i <= s.length() - 10; i++) {
            m[s.substr(i, 10)]++;
        }
        
        for(auto&[str, cnt] : m) {
            if(cnt > 1) res.push_back(str);
        }
        return res;
    }
};