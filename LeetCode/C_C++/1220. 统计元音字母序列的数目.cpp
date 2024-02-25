class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        long f[n][5];
        memset(f, 0, sizeof f);
        for(int i = 0; i < 5; i++) {
            f[0][i] = 1;
        }
        for(int i = 0; i < n-1; i++) {
            f[i + 1][1] += f[i][0];
            f[i + 1][0] += f[i][1];
            f[i + 1][2] += f[i][1];
            f[i + 1][0] += f[i][2];
            f[i + 1][1] += f[i][2];
            f[i + 1][3] += f[i][2];
            f[i + 1][4] += f[i][2];
            f[i + 1][2] += f[i][3];
            f[i + 1][4] += f[i][3];
            f[i + 1][0] += f[i][4];
            for(int j = 0; j < 5; j++) {
                f[i + 1][j] %= mod;
            }
        }
        long res = 0;
        for(int i = 0; i < 5; i++) {
            res += f[n-1][i];
        }
        return res % mod;
    }
};