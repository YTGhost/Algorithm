class Solution {
public:
    bool isPrime(int n) {
        // 处理边界情况
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        // 排除所有能被2或3整除的数
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        // 检查从5开始的所有数，直到平方根
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;
        int res = -1, cnt = 0;
        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        function<void(int, int)> handle = [&](int i, int j) {
            for(int k = 0; k < 8; k++) {
                int x = i, y = j;
                int t = mat[x][y];
                x = x + dx[k], y = y + dy[k];
                while(x >= 0 && x < m && y >= 0 && y < n) {
                    t = t * 10 + mat[x][y];
                    if(t > 10 && isPrime(t)) {
                        mp[t]++;
                        if(mp[t] > cnt) {
                            cnt = mp[t];
                            res = t;
                        } else if(mp[t] == cnt && t > res) {
                            res = t;
                        }
                    }
                    x = x + dx[k], y = y + dy[k];
                }
            }
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                handle(i, j);
            }
        }
        return res;
    }
};