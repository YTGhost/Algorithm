class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto num : target) {
            m[num]++;
        }
        for(auto num : arr) {
            if(m[num]) {
                m[num]--;
            } else {
                return false;
            }
        }
        return true;
    }
};