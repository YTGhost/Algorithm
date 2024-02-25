class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int len = 0;
        int row = 0;
        for(auto c : s) {
            int temp = len + widths[c - 'a'];
            if(temp > 100) {
                row++;
                len = widths[c - 'a'];
            } else {
                len += widths[c - 'a'];
            }
        }
        if(len) row++;
        return vector<int> {row, len};
    }
};