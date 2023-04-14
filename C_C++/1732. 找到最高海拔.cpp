class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int latitude = 0, res = 0;
        for(auto num : gain) {
            latitude += num;
            res = max(res, latitude);
        }
        return res;
    }
};