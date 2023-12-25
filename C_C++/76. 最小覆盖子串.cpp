class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int n = s.size(), m = t.size();
        int resL = -1, resR = -1;
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            hash1[t[i]]++;
            if(hash1[t[i]] == 1) {
                cnt++;
            }
        }
        int l = 0;
        for(int r = 0; r < n; r++) {
            hash2[s[r]]++;
            if(hash2[s[r]] == hash1[s[r]]) {
                cnt--;
            }
            while(cnt == 0) {
                if(resL == -1 || resR - resL + 1 > r - l + 1) {
                    resL = l, resR = r;
                }
                hash2[s[l]]--;
                if(hash2[s[l]] < hash1[s[l]]) {
                    cnt++;
                }
                l++;
            }
        }
        return resL == -1 ? "" : s.substr(resL, resR - resL + 1);
    }
};

class Solution {
public:
    unordered_map<char, int> record, count;

    bool check() {
        for(auto item : record){
            if(count[item.first] < item.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(auto item : t) record[item]++;
        int l = 0, r = -1;
        int ansL = -1, len = INT_MAX;
        while(r < (int)s.length())
        {
            if(record.find(s[++r]) != record.end()) count[s[r]]++;
            while(l <= r && check())
            {
                if(r-l+1 < len)
                {
                    ansL = l;
                    len = r-l+1;
                }
                if(record.find(s[l]) != record.end()) count[s[l]]--;
                l++;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }
};