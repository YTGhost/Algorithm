class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, t = i;
            while(t) {
                sum += t % 10;
                t /= 10;
            }
            m[sum]++;
            res = max(res, m[sum]);
        }
        return res;
    }
};