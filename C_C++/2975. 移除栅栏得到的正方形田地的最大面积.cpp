class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int MOD = 1e9 + 7;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.insert(hFences.begin(), 1);
        vFences.insert(vFences.begin(), 1);
        hFences.push_back(m);
        vFences.push_back(n);
        unordered_set<int> s;
        for(int i = 0; i < hFences.size() - 1; i++) {
            for(int j = i + 1; j < hFences.size(); j++) {
                s.insert(hFences[j] - hFences[i]);
            }
        }
        long long res = -1;
        for(int i = 0; i < vFences.size() - 1; i++) {
            for(int j = i + 1; j < vFences.size(); j++) {
                int w = vFences[j] - vFences[i];
                if(s.count(w)) {
                    res = max(res, (long long)w * w);
                }
            }
        }
        return res % MOD;
    }
};