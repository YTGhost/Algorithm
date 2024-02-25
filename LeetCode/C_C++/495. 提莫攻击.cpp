class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, t = timeSeries[0] + duration - 1;
        for(int i = 1; i < timeSeries.size(); i++) {
            if(t < timeSeries[i]) res += duration;
            else res += timeSeries[i] - timeSeries[i-1];
            t = timeSeries[i] + duration - 1;
        }
        return res + duration;
    }
};