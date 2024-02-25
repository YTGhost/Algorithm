class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int cnt[26], res = 0;
        for(int i = 0; i < n; i++)
        {
            memset(cnt, 0, sizeof cnt);
            for(int j = i; j < n; j++)
            {
                cnt[s[j] - 'a']++;
                int maxv = -1, minv = INT_MAX;
                for(int k = 0; k < 26; k++)
                {
                    if(cnt[k] > 0) {
                        maxv = max(maxv, cnt[k]);
                        minv = min(minv, cnt[k]);
                    }
                }
                res += maxv - minv;
            }
        }
        return res;
    }
};