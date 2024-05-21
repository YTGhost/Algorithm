class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> mp;
        unordered_set<int> st;
        vector<vector<int>> res(2);
        for(auto match : matches) {
            auto winner = match[0], loser = match[1];
            mp[loser]++;
            st.insert(winner);
            st.insert(loser);
        }
        for(auto &[key, value] : mp) {
            if(value == 1) {
                res[1].push_back(key);
            }
            st.erase(key);
        }
        res[0] = vector<int>(st.begin(), st.end());
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res; 
    }
};