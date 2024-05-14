class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int, int> mp;
        for(auto task : tasks) {
            mp[task]++;
        }
        int res = 0;
        for(auto &[_, cnt] : mp) {
            if(cnt == 1) return -1;
            res += (cnt + 2) / 3;
        }
        return res;
    }
};