class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<int> res;
        if(pLen > sLen) return res;
        vector<int> sCnt(26);
        vector<int> pCnt(26);
        for(int i = 0; i < pLen; i++) {
            sCnt[s[i] - 'a']++;
            pCnt[p[i] - 'a']++;
        }
        if(sCnt == pCnt) {
            res.push_back(0);
        }
        for(int i = 0; i < sLen - pLen; i++) {
            sCnt[s[i] - 'a']--;
            sCnt[s[i + pLen] - 'a']++;
            if(sCnt == pCnt) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    bool check(vector<int> &c1, vector<int> &c2) {
        for(int i = 0; i < 26; i++) {
            if(c1[i] != c2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, c1(26), c2(26);
        int n = s.length(), m = p.length();
        for(int i = 0; i < m; i++) c2[p[i] - 'a']++;
        for(int l = 0, r = 0; r < n; r++) {
            c1[s[r] - 'a']++;
            if(r - l + 1 > m) c1[s[l++] - 'a']--;
            if(check(c1, c2)) res.push_back(l);
        }
        return res;
    }
};