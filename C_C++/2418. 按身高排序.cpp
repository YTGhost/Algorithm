class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return heights[x] > heights[y];
        });
        vector<string> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = names[idx[i]];
        }
        return res;
    }
};