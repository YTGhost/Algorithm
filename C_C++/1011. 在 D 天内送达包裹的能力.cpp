class Solution {
public:
    bool check(vector<int>& weights, int t, int days) {
        int cnt = 0, n = weights.size(), sum = 0;
        for(int i = 0; i < n; i++) {
            sum += weights[i];
            if(sum > t) {
                cnt++;
                sum = 0;
                i--;
            }
        }
        cnt++;
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = accumulate(weights.begin(), weights.end(), 0);
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(weights, mid, days)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

class Solution {
public:
    bool check(vector<int>& weights, int mid, int D) {
        int n = weights.size();
        int cnt = 0;
        for(int i = 0, sum = 0; i < n; sum = 0)
        {
            while(i < n && sum + weights[i] <= mid) {
                sum += weights[i];
                i++;
            }
            cnt++;
        }
        return cnt <= D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int m = 0, sum = 0;
        for(auto weight : weights)
        {
            m = max(m, weight);
            sum += weight;
        }
        int l = m, r = sum;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(weights, mid, D)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};