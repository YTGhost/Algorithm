class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> hash(26);
        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] <= 2) res += hash[i];
            else if (hash[i] % 2 == 0) res += 2;
            else res++;
        }
        return res;
    }
};