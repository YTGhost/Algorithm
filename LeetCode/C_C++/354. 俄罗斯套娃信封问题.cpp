// O(nlogn)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b){
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> f(n+1);
        f[0] - -2e9;
        int len = 0;
        for(int i = 0; i < n; i++)
        {
            int l = 0, r = len;
            while(l < r)
            {
                int mid = l + r + 1>> 1;
                if(f[mid] < envelopes[i][1]) l = mid;
                else r = mid - 1;
            }
            len = max(len, l + 1);
            f[l+1] = envelopes[i][1];
        }
        return len;
    }
};

// O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> f(n+1);
        for(int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for(int j = 1; j < i; j++)
                if(envelopes[j-1][0] < envelopes[i-1][0] && envelopes[j-1][1] < envelopes[i-1][1])
                    f[i] = max(f[i], f[j] + 1);
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
            res = max(res, f[i]);
        return res;
    }
};