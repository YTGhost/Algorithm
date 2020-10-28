class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for(auto item : arr) m[item]++;
        for(auto item : m) s.insert(item.second);
        return s.size() == m.size() ? true : false;
    }
};