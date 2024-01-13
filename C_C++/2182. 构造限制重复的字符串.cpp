class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int hash[26];
        memset(hash, 0, sizeof(hash));
        for(auto c : s) {
            hash[c - 'a']++;
        }
        string res = "";
        int cnt = 0;
        for(int i = 25, j = 24; i >= 0 && j >= 0; ) {
            if(hash[i] == 0) {
                i--;
                cnt = 0;
            } else if(cnt < repeatLimit) {
                cnt++;
                res += 'a' + i;
                hash[i]--;
            } else if(hash[j] == 0 || j >= i) {
                j--;
            } else {
                cnt = 0;
                res += 'a' + j;
                hash[j]--;
            }
        }
        return res;
    }
};