class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](const auto &a, const auto &b) {
            return a[1] > b[1];
        });
        int i = 0;
        while(truckSize && i < boxTypes.size())
        {
            if(boxTypes[i][0] <= truckSize) {
                res += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
                i++;
            } else {
                res += truckSize * boxTypes[i][1];
                break;
            }
        }
        return res;
    }
};