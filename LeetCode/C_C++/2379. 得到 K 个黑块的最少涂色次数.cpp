class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += blocks[i] == 'W' ? 1 : 0;
        }
        int res = sum;
        for(int i = k; i < n; i++) {
            sum -= blocks[i - k] == 'W' ? 1 : 0;
            sum += blocks[i] == 'W' ? 1 : 0;
            res = min(res, sum);
        }
        return res;
    }
};