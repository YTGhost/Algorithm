class Solution {
public:
    int countPairs(vector<int>& d) {
        int res = 0;
        int mod = 1e9 + 7;
        unordered_map<int, int> m;
        for(auto x : d){
            for(int i = 0; i <= 21; i++) {
                int t = (1 << i) - x;
                if(m.count(t)) res = (res + m[t]) % mod;
            }
            m[x]++;
        }
        return res;
    }
};