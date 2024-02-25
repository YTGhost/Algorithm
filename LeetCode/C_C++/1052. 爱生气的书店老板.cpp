class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size(), res = 0;
        vector<int> pre(n, 0);
        if(grumpy[0] == 0) pre[0] = customers[0];
        for(int i = 1; i < n; i++)
        {
            if(grumpy[i] == 1) pre[i] = pre[i-1];
            else pre[i] = pre[i-1] + customers[i];
        }
        int window = 0;
        for(int i = 0; i < X; i++) window += customers[i];
        res = max(res, window + pre[n-1] - pre[X-1]);
        for(int i = X; i < n; i++)
        {
            window = window - customers[i-X] + customers[i];
            int a = pre[i-X], b = pre[n-1] - pre[i];
            res = max(res, window + a + b);
        }
        return res;
    }
};