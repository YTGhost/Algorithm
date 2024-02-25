class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        int maxDef = 0, res = 0;
        for(auto &item : properties) {
            if(item[1] < maxDef) res++;
            else maxDef = item[1];
        }
        return res;
    }
};