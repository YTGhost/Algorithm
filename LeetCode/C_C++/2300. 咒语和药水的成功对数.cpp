class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        potions.push_back(-1);
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int l = 0, r = m;
            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if((long long)potions[mid] * spells[i] >= success) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            res[i] = m - l;
        }
        return res;
    }
};