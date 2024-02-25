class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> f(k+1, 0);
        vector<int> res(k+1, 0);
        f[0] = 1;
        for(int i = 1; i <= k; i++)
            for(int j = i; j >= 1; j--)
                f[j] += f[j-1];
        for(int i = 0; i <= k; i++)
            res[i] = f[i];
        return res;
    }
};