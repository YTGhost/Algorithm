const int INF = 0x3f3f3f3f;
int f[105][25][105];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // f[i][j][k] 为前i间房子，第i间房子的颜色编号为j，且形成的分区数量为k的所有方案中的最小上色成本
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                f[i][j][0] = INF;
        
        for(int i = 1; i <= m; i++) {
            int color = houses[i-1];
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= target; k++) {
                    // 如果分区数量大于房子数量，状态无效
                    if(k > i) {
                        f[i][j][k] = INF;
                        continue;
                    }

                    // 第i间房间已经上色
                    if(color != 0) {
                        if(j == color) {
                            int tmp = INF;
                            // 先从所有 第i间房形成新分区 方案中选最优
                            for(int p = 1; p <= n; p++) {
                                if(p != j) {
                                    tmp = min(tmp, f[i-1][p][k-1]);
                                }
                            }
                            // 再跟 第i间房不形成新分区 进行比较
                            f[i][j][k] = min(tmp, f[i-1][j][k]);
                        } else {
                            f[i][j][k] = INF;
                        }
                    } else { // 第i间房没上色
                        int u = cost[i-1][j-1];
                        int tmp = INF;
                        for(int p = 1; p <= n; p++) {
                            if(p != j) {
                                tmp = min(tmp, f[i-1][p][k-1]);
                            }
                        }
                        f[i][j][k] = min(tmp, f[i-1][j][k]) + u;
                    }
                }
            }
        }
        int res = INF;
        for(int i = 1; i <= n; i++) {
            res = min(res, f[m][i][target]);
        }
        return res == INF ? -1 : res;
    }
};