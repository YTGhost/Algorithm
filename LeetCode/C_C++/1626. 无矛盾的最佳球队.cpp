class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> team;
        for(int i = 0; i < n; i++) {
            team.push_back({scores[i], ages[i]});
        }
        sort(team.begin(), team.end());
        vector<int> f(n, 0);
        f[0] = team[0].first;
        int res = f[0];
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; --j) {
                if(team[j].second <= team[i].second) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += team[i].first;
            res = max(res, f[i]);
        }
        return res;
    }
};