class Solution {
public:
    int cnts[1440 * 2 + 10];
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() > 1440) return 0;
        for(string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            cnts[hour * 60 + minute]++;
            cnts[hour * 60 + minute + 1440]++;
        }
        int res = 1440, last = -1;
        for(int i = 0; i <= 1440 * 2; i++) {
            if(cnts[i] == 0) continue;
            else if(cnts[i] > 1) return 0;
            else if(last != -1) res = min(res, i - last);
            last = i;
        }
        return res;
    }
};