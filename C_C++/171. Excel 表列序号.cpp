class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int index = 0;
        int res = 0;
        for(int i = n-1; i >= 0; i--, index++) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, index);
        }
        return res;
    }
};