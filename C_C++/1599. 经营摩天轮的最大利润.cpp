class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int cnt = 0, sum = 0, res = 0, maxSum = 0, op = 0;
        for(int i = 0; i < n; i++) {
            op++;
            cnt += customers[i];
            int t = min(cnt, 4);
            cnt -= t;
            sum += boardingCost * t - runningCost;
            if(sum > maxSum) {
                maxSum = sum;
                res = op;
            }
        }
        while(cnt) {
            op++;
            int t = min(cnt, 4);
            cnt -= t;
            if(boardingCost * t <= runningCost) break;
            sum += boardingCost * t - runningCost;
            if(sum > maxSum) {
                sum = maxSum;
                res = op;
            }
        }
        return sum > 0 ? res : -1;
    }
};