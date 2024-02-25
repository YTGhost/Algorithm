class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1, n = s.length();
        vector<int> arr(26, 310);
        for(int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            arr[t] = min(arr[t], i);
            res = max(res, i - arr[t] - 1);
        }
        return res;
    }
};