class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n + 1);
        vector<bool> toTrust(n + 1);
        for (auto item : trust) {
            toTrust[item[0]] = true;
            trusted[item[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!toTrust[i] && trusted[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> m1, m2;
        for(auto item : trust) {
            m1[item[0]]++;
            m2[item[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(m1[i] == 0 && m2[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};