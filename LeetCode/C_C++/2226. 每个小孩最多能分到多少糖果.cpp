class Solution {
public:
    bool check(vector<int>& candies, int t, long long k) {
        long long sum = 0;
        for(auto candy : candies) {
            sum += candy / t;
        }
        return sum >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if(k > total) return 0;
        int start = 1, end = *max_element(candies.begin(), candies.end()) + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(candies, mid, k)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start - 1;
    }
};