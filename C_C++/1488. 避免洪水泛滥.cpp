class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> hash;
        set<int> s;
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                s.insert(i);
            } else {
                res[i] = -1;
                if(hash.count(rains[i])) {
                    auto it = s.lower_bound(hash[rains[i]]);
                    if(it == s.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    s.erase(it);
                }
                hash[rains[i]] = i;
            }
        }
        return res;
    }
};