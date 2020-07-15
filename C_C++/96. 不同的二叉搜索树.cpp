class Solution {
public:
/* G(n) = f(1) + f(2) +...+ f(n)
    f(i) = G(i-1) * G(n-i)
    G(n) = G(0) * G(n-1) + G(1) * G(n-2) +...+ G(n-1) * G(0)
 */
    int numTrees(int n) {
        int G[n+1];
        int sum;
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            G[i] = 0;
            for(int j = 1; j <= i ; j++)
            {
                G[i] += G[j-1] * G[i-j];
            }
        }
        return G[n]; 
    }
};

// 每日一题打卡
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
            {
                G[i] += G[j-1] * G[i-j];
            }
        return G[n];
    }
};