class Solution {
public:
    bool dfs(string &t, int pos, int preSum, int target) {
        if(pos == t.size()) {
            return preSum == target;
        }
        int sum = 0;
        for(int i = pos; i < t.size(); i++) {
            sum = sum * 10 + t[i] - '0';
            if(preSum + sum > target) {
                break;
            }
            if(dfs(t, i + 1, preSum + sum, target)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            string t = to_string(i * i);
            if(dfs(t, 0, 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};