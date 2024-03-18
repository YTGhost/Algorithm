class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if(sum < desiredTotal) {
            return false;
        }
        unordered_map<int, bool> memo;
        function<bool(int, int)> dfs = [&](int userdNumbers, int currentTotal) {
            if(!memo.count(userdNumbers)) {
                bool res = false;
                for(int i = 0; i < maxChoosableInteger; i++) {
                    if(((userdNumbers >> i) & 1) == 0) {
                        if(i + 1 + currentTotal >= desiredTotal) {
                            res = true;
                            break;
                        }
                        if(!dfs(userdNumbers | (1 << i), currentTotal + i + 1)) {
                            res = true;
                            break;
                        }
                    }
                }
                memo[userdNumbers] = res;
            }
            return memo[userdNumbers];

        };
        return dfs(0, 0);
    }
};