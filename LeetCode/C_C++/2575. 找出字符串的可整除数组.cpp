class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> res(n);
        long long num = 0;
        for(int i = 0; i < n; i++) {
            num = (num * 10 + word[i] - '0') % m;
            if(num == 0) res[i] = 1;
        }
        return res;
    }
};