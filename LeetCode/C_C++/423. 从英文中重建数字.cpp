class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> cnt;
        vector<int> t(10);
        for(auto c : s) {
            cnt[c]++;
        }
        t[0] = cnt['z'];
        t[2] = cnt['w'];
        t[4] = cnt['u'];
        t[6] = cnt['x'];
        t[8] = cnt['g'];
        t[3] = cnt['h'] - t[8];
        t[5] = cnt['f'] - t[4];
        t[7] = cnt['s'] - t[6];
        t[1] = cnt['o'] - t[0] - t[2] - t[4];
        t[9] = cnt['i'] - t[5] - t[6] - t[8];
        string res;
        for(int i = 0; i < 10; i++) {
            res += string(t[i], '0' + i);
        }
        return res;
    }
};