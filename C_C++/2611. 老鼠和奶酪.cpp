class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int res = 0, n = reward1.size();
        vector<int> diff(n);
        for(int i = 0; i < n; i++) {
            res += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }
        sort(diff.begin(), diff.end());
        for(int i = n - 1; i >= n - k; i--) {
            res += diff[i];
        }
        return res;
    }
};