class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1, r = *min_element(time.begin(), time.end()) * (long long)totalTrips + 1;
        function<bool(long long)> check = [&](long long target) {
            long long sum = 0;
            for (auto item : time) {
                sum += target / item;
            }
            return sum >= totalTrips;
        };
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

class Solution {
public:
    bool check(vector<int>& time, long long t, int totalTrips) {
        long long sum = 0;
        for(auto item : time) {
            sum += t / item;
        }
        return sum >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 0, end = *max_element(time.begin(), time.end()) * (long long)totalTrips;
        while(start < end) {
            long long mid = start + (end - start) / 2;
            if(check(time, mid, totalTrips)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};