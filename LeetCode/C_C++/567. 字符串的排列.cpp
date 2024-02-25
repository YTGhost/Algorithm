class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> st(26, 0);
        for(auto c : s1)
        {
            int cnt = c - 'a';
            st[cnt]++;
        }
        int l = 0, r = 0, n = s1.size(), m = s2.size();
        while(r < m)
        {
            int cur = s2[r] - 'a';
            st[cur]--;
            while(st[cur] < 0) {
                st[s2[l++] - 'a']++;
            }
            if(r - l + 1 == n) return true;
            r++;
        }
        return false;
    }
};