class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> mp(26, 0);
        long long sum = 0;
        int n = s.length();
        string t = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                mp[s[i] - 'a']++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                sum += mp[s[i] - 'a'];
            } else {
                int minVal = INT_MAX;
                char c;
                for(int j = 0; j < 26; j++) {
                    if(mp[j] < minVal) {
                        minVal = mp[j];
                        c = 'a' + j;
                    }
                }
                t += c;
                mp[c - 'a']++;
            }
        }
        sort(t.begin(), t.end());
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                s[i] = t[idx++]; 
            }
        }
        return s;
    }
};