class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        if (start > destination) {
            swap(start, destination);
        }
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + distance[i];
        }
        vector<int> suffixSum(n + 1);
        for (int i = 0; i < n; i++) {
            suffixSum[i + 1] = suffixSum[i] + distance[n - i - 1];
        }
        return min(prefixSum[destination] - prefixSum[start], prefixSum[start] + suffixSum[n - destination]);
    }
};