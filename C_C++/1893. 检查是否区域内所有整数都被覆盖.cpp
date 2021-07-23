class Solution {
public:
    vector<int> b = vector<int>(55);
    void insert(int l, int r, int c) {
        b[l] += c;
        b[r+1] -= c;
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(auto range : ranges) {
            insert(range[0], range[1], 1);
        }
        for(int i = 1; i < b.size(); i++) {
            b[i] += b[i-1];
        }
        for(int i = left; i <= right; i++) {
            if(b[i] == 0) return false;
        }
        return true;
    }
};