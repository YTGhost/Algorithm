class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> customersPrefixSum(n + 1);
        vector<int> excludeGrumpyPrefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            customersPrefixSum[i + 1] = customersPrefixSum[i] + customers[i];
            excludeGrumpyPrefixSum[i + 1] = excludeGrumpyPrefixSum[i];
            if(grumpy[i] == 0) {
                excludeGrumpyPrefixSum[i + 1] += customers[i];
            }
        }
        int res = customersPrefixSum[minutes] + excludeGrumpyPrefixSum[n] - excludeGrumpyPrefixSum[minutes];
        for(int i = 1; i <= n - minutes; i++) {
            int sum = customersPrefixSum[i + minutes] - customersPrefixSum[i] + excludeGrumpyPrefixSum[i] + excludeGrumpyPrefixSum[n] - excludeGrumpyPrefixSum[minutes + i];
            res = max(res, sum);
        }
        return res;
    }
};

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