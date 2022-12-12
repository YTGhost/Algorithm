class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), res = 0;
        for(int i = 0; i < n; i++) {
            vector<int> hash(26);
            int maxFreq = 0;
            for(int j = i; j < n; j++) {
                hash[s[j] - 'a']++;
                maxFreq = max(maxFreq, hash[s[j] - 'a']);
                int minFreq = s.length();
                for(int k = 0; k < 26; k++) {
                    if(hash[k] > 0) {
                        minFreq = min(minFreq, hash[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }
        return res; 
    }
};