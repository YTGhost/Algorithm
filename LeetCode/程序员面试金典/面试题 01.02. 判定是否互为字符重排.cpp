class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> t(128, 0);
        if (n != m) return false;
        for(int i = 0; i < n; i++) {
            t[s1[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(t[s2[i]] == 0) return false;
            t[s2[i]]--;
        }
        return true;
    }
};