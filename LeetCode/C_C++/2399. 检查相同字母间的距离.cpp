class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> hash(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            if(hash[t] == -1) {
                hash[t] = i;
            } else {
                hash[t] = i - hash[t] - 1;
                if(hash[t] != distance[t]) return false;
            }
        }
        return true;
    }
};