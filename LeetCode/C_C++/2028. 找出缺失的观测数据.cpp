class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = n + m;
        int totalSum = mean * total;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int rest = totalSum - sum;
        if(rest > n * 6 || rest < n) {
            return vector<int>{};
        }
        int avg = rest / n;
        int extra = rest % n;
        vector<int> res(n, avg);
        for(int i = 0; i < extra; i++) {
            res[i] = avg + 1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean * (n + m);
        for(int i = 0; i < m; i++) {
            total -= rolls[i];
        }
        if(total > 6 * n || total < n) return vector<int>();
        vector<int> res(n, total / n);
        if(total / n * n < total) {
            int diff = total - (total / n * n);
            int idx = 0;
            while(diff-- > 0) {
                res[idx++]++;
            }
        }
        return res;
    }
};