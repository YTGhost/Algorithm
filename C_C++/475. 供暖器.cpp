class Solution {
public:
    int lower_bound(vector<int>& heaters, int target) {
        int l = 0, r = heaters.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(heaters[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for(auto house : houses) {
            int a = lower_bound(heaters, house);
            int b = lower_bound(heaters, house) - 1;
            int rightDistance = a >= heaters.size() ? INT_MAX : heaters[a] - house;
            int leftDistance = b < 0 ? INT_MAX : house - heaters[b];
            int t = min(rightDistance, leftDistance);
            res = max(res, t);
        }
        return res;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = (int) 1e9;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(houses, heaters, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool check(vector<int>& houses, vector<int>& heaters, int mid) {
        int n = houses.size(), m = heaters.size();
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && heaters[j] + mid < houses[i]) j++;
            if(j < m && heaters[j] - mid <= houses[i] && heaters[j] + mid >= houses[i]) continue;
            return false;
        }
        return true;
    }
};