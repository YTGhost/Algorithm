class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size(), n = score[0].size();
        function<bool(vector<int>&, vector<int>&)> cmp = [&](vector<int>& a, vector<int>& b) {
            return a[k] > b[k];
        };
        sort(score.begin(), score.end(), cmp);
        return score;
    }
};