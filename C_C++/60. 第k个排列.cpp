class Solution {
public:
    int st[10];
    string getPermutation(int n, int k) {
        int factorial[n];
        string res;
        vector<int> st(n+1, 1);
        factorial[0] = 1;
        for(int i = 1; i < n; i++) factorial[i] = i * factorial[i-1];
        k--;
        for(int i = 1; i <= n; i++) {
            int digit = k / factorial[n-i] + 1;
            for(int j = 1; j <= n; j++) {
                digit -= st[j];
                if(!digit) {
                    res += (j + '0');
                    st[j] = 0;
                    break;
                }
            }
            k %= factorial[n-i];
        }
        return res;
    }
};