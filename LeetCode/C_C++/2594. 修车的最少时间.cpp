class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        using ll = long long;
        ll l = 1, r = 1ll * ranks[0] * cars * cars;
        auto check = [&](ll mid) {
            ll cnt = 0;
            for(auto rank : ranks) {
                cnt += sqrt(mid / rank);
            }
            return cnt >= cars;
        };
        while(l < r) {
            ll mid = l + r >> 1;
            if(check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};