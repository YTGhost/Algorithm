class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        int res = -1;
        for(auto item : arr) m[item]++;
        for(auto item : m)
            if(item.first == item.second)
                res = max(res, item.second);
        return res;
    }
};