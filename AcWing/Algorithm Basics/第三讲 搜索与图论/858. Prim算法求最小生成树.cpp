#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;    // 最小生成树里边所有边的长度之和
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        if(i && dist[t] == INF) return INF; // 当前距离最近的点到集合的距离为正无穷，即不连通
        
        if(i) res += dist[t];   // 只要不是第一条边，就加到res里
        
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);    // 更新点到集合的距离
        
        st[t] = true;
    }
    
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);
    
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if(t == INF) puts("impossible");
    else printf("%d\n", t);
    
    return 0;
}