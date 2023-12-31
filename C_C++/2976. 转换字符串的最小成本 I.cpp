class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int w[26][26];
        memset(w, 0x3f, sizeof(w));
        for(int i = 0; i < 26; i++) {
            w[i][i] = 0;
        }
        for(int i = 0; i < original.size(); i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            w[a][b] = min(w[a][b], cost[i]);
        }
        auto f = move(w);
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < source.size(); i++) {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(f[a][b] == 0x3f3f3f3f) {
                return -1;
            }
            res += f[a][b];
        }
        return res;
    }
};