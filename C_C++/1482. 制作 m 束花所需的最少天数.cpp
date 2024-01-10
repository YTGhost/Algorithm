class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();
        vector<bool> status(n);
        int cnt = 0, t = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= day) {
                status[i] = true;
                t++;
                if(t == k) {
                    cnt++;
                    t = 0;
                }
            } else {
                t = 0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > bloomDay.size() / k) {
            return -1;
        }
        int start = 0, end = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(bloomDay, m, k, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};