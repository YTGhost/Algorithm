class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), mod = 1e9 + 7, res = 0;
        vector<int> f(n, 1);
        for(int i = 0; i < n; i++) {
            for(int l = 0, r = i - 1; l <= r; l++) {
                while(l <= r && (long long)arr[l] * arr[r] > arr[i]) {
                    r--;
                }
                if(l <= r && (long long)arr[l] * arr[r] == arr[i]) {
                    if(arr[l] == arr[r]) {
                        f[i] = (f[i] + f[l] * f[r]) % mod;
                    } else {
                        f[i] = (f[i] + f[l] * f[r] * 2) % mod;
                    }
                }
            }
            res = (res + f[i]) % mod;
        }
        return res;
    }
};