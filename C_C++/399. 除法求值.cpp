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