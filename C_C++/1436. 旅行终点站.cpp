class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        unordered_map<string, int> m;
        for(auto path : paths) {
            s.insert(path[0]), s.insert(path[1]);
            m[path[0]]++;
        }
        string res;
        for(auto city : s) {
            if(m.count(city) == 0) {
                res = city;
                break;
            }
        }
        return res;
    }
};