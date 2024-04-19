class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        vector<int> prefixSum(n + 1);
        unordered_map<char, int> hash{
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4}
        };
        unordered_map<int, int> mp;
        mp[0] = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            if(hash.count(s[i])) {
                prefixSum[i + 1] ^= (1 << hash[s[i]]);
            }
            if(mp.find(prefixSum[i + 1]) == mp.end()) {
                mp[prefixSum[i + 1]] = i + 1;
            } else {
                res = max(res, i + 1 - mp[prefixSum[i + 1]]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(1 << 5, INT_MAX);
        int state = 0, ans = 0;
        pre[0] = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a') state ^= 1 << 4;
            else if(s[i] == 'e') state ^= 1 << 3;
            else if(s[i] == 'i') state ^= 1 << 2;
            else if(s[i] == 'o') state ^= 1 << 1;
            else if(s[i] == 'u') state ^= 1;
            if(pre[state] == INT_MAX) pre[state] = i;
            else ans = max(ans, i - pre[state]);
        }
        return ans;
    }
};