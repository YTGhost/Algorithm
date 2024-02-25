class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int res = word[0] - word[n - 1] + 2;
        for(int i = 1; i < n; i++) {
            res += (word[i] - word[i - 1] + 2) % 3;
        }
        return res;
    }
};