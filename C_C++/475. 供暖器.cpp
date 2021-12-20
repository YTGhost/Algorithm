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