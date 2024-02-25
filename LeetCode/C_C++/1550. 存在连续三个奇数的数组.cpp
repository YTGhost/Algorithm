class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int cnt = 0;
        for(auto num : arr) {
            if(num % 2) {
                cnt++;
            } else {
                cnt = 0;
            }
            if(cnt == 3) return true;
        }
        return false;
    }
};