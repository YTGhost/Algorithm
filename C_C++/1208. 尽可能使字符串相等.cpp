class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);
        for(int i = 0; i < n; i++)
            diff[i] = abs(s[i] - t[i]);

        int sum = 0, res = 0;
        int start = 0, end = 0;
        while(end < n) {
            sum += diff[end];
            while(sum > maxCost) {
                sum -= diff[start];
                start++;
            }
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};