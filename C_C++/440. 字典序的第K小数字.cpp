class Solution {
public:
    int getSteps(int cur, long n) {
        int steps = 0;
        long first = cur, last = cur;
        while(first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0) {
            int steps = getSteps(cur, n);
            if(steps <= k) {
                k -= steps;
                cur++;
            } else {
                cur = cur * 10;
                k--;
            }
        }
        return cur;
    }
};