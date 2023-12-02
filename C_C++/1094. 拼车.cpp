class Solution {
public:
    int b[1010];
    void insert(int l, int r, int c) {
        b[l] += c;
        b[r + 1] -= c;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(auto trip : trips) {
            insert(trip[1], trip[2] - 1, trip[0]);
        }
        for(int i = 0; i <= 1000; i++) {
            if(i != 0) {
                b[i] += b[i - 1];
            }
            if(b[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};