class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> m;
        vector<int> res;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            m[s[i] - 'a'] = i;
        }
        int l = 0, t = 0;
        for(int r = 0; r < n; r++) {
            t = max(t, m[s[r] - 'a']);
            if(r == t) {
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return res;
    }
};