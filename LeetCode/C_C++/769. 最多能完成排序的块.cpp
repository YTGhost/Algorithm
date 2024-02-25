class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size(), maxValue = 0;
        for(int i = 0; i < n; i++) {
            maxValue = max(maxValue, arr[i]);
            res += maxValue == i;
        }
        return res;
    }
};