class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (possible[i] == 0 ? -1 : 1);
        }
        int res = -1;
        for (int i = 1; i < n; i++) {
            if (prefixSum[i] > prefixSum[n] - prefixSum[i]) {
                res = i;
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        for(int i = 0; i < n; i++) {
            if (possible[i] == 0) {
                possible[i] = -1;
            }
        }
        int total = accumulate(possible.begin(), possible.end(), 0);
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += possible[i];
            int t = total - sum;
            if(sum > t) {
                return i + 1;
            }
        }
        return -1;
    }
};