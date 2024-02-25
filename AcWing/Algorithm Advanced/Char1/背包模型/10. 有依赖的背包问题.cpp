#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int f[N][N], v[N], w[N];
int e[N], ne[N], h[N], idx;

// 邻接表存树
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for(int i = h[u]; i != -1; i = ne[i]) // 遍历物品组
    {
        int son = e[i];
        dfs(son);
        for(int j = m - v[u]; j >= 0 ; j--) // 循环体积
            for(int k = 0; k <= j ; k++) // 循环决策
                f[u][j] = max(f[u][j], f[u][j-k] + f[son][k]);
    }
    // 把u加入
    for(int i = m; i >= v[u]; i--) f[u][i] = f[u][i-v[u]] + w[u];
    // 体积小于v[u]意味着无法满足依赖
    for(int i = 0; i < v[u]; i++) f[u][i] = 0;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    int root;
    for(int i = 1; i <= n; i++)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == -1) root = i;
        else add(p, i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}