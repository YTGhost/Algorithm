class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        unordered_set<string> s;
        vector<double> res;
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            string x = equations[i][0], y = equations[i][1];
            m[x][y] = values[i], m[y][x] = 1 / values[i];
            s.insert(x), s.insert(y);
        }
        for(auto k : s) {
            for(auto i : s) {
                for(auto j : s) {
                    if(m[i][k] && m[k][j]) {
                        m[i][j] = m[i][k] * m[k][j];
                    }
                }
            }
        }
        for(auto query : queries) {
            auto x = query[0], y = query[1];
            if(m[x][y]) {
                res.push_back(m[x][y]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> set;
        unordered_map<string, unordered_map<string, double>> map;
        vector<double> res;
        for(int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double c = values[i];
            map[a][b] = c, map[b][a] = 1 / c;
            set.insert(a);
            set.insert(b);
        }

        for(auto k : set)
            for(auto i : set)
                for(auto j : set)
                    if(map[i][k] && map[j][k])
                        map[i][j] = map[i][k] * map[k][j];
        for(auto q : queries)
        {
            string a = q[0];
            string b = q[1];
            if(map[a][b]) res.push_back(map[a][b]);
            else res.push_back(-1);
        }
        return res;
    }
};