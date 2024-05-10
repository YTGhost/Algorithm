class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        for(auto item : batteryPercentages) {
            if(item > res) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int cnt = 0, res = 0;
        for(int i = 0; i < n; i++) {
            batteryPercentages[i] = max(0, batteryPercentages[i] - cnt);
            if(batteryPercentages[i] > 0) {
                res++;
                cnt++;
            }
        }
        return res;
    }
};