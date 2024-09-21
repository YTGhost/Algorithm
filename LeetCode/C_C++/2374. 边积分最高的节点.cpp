class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n);
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }
        long long res = 0, temp = score[0];
        for (int i = 1; i < n; i++) {
            if (score[i] > temp) {
                temp = score[i];
                res = i;
            }
        }
        return res;
    }
};