class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& beans) {
        int n = beans.size();
        vector<long long> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + beans[i];
        }
        return prefixSum;
    }
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        vector<long long> prefixSum = getPrefixSum(beans);
        long long sum = prefixSum[n];
        long long res = sum;
        for(int i = 0; i < n; i++) {
            res = min(res, sum - (long long)(n - i) * beans[i]);
        }
        return res;
    }
};