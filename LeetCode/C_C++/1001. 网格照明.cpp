class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, dg, udg;
        unordered_map<long long, int> light;
        vector<int> res;
        for(auto lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            if(light[(long long)n * x + y]) continue;
            light[(long long)n * x + y] = 1;
            row[x]++, col[y]++, dg[x - y]++, udg[x + y]++;
        }
        for(auto query : queries) {
            int x = query[0], y = query[1];
            if(row[x] || col[y] || dg[x - y] || udg[x + y]) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            for(int i = x - 1; i <= x + 1; i++) {
                for(int j = y - 1; j <= y + 1; j++) {
                    if(i < 0 || i >= n || j < 0 || j >= n) continue;
                    if(light[(long long)n * i + j]) {
                        light[n * i + j] = 0;
                        row[i]--, col[j]--, dg[i - j]--, udg[i + j]--;
                    }
                }
            }
        }
        return res;
    }
};