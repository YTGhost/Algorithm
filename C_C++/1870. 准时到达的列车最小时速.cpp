class Solution {
public:
    bool check(vector<int>& dist, int t, double hour) {
        double sum = 0;
        for(int i = 0; i < dist.size(); i++) {
            if(i != dist.size() - 1) {
                sum += ceil((double)dist[i] / t);
            } else {
                sum += (double)dist[i] / t;
            }
        }
        return sum <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int start = 1, end = 1e7 + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(dist, mid, hour)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start == 1e7 + 1 ? -1 : start;
    }
};