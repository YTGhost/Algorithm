#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N], dist[N], cnt[N], sum[N], w[N];
bool st[N];
int n, m, c1, c2;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[c1] = 0, cnt[c1] = 1, sum[c1] = w[c1];
    
    for(int i = 0; i < n-1; i++)
    {
        int t = -1;
        for(int j = 0; j < n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
        
        for(int j = 0; j < n; j++) {
            if(dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                cnt[j] = cnt[t];
                sum[j] = sum[t] + w[j];
            } else if(dist[j] == dist[t] + g[t][j]) {
                cnt[j] += cnt[t];
                sum[j] = max(sum[j], sum[t] + w[j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i++) cin >> w[i];
    memset(g, 0x3f, sizeof g);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    dijkstra();
    
    cout << cnt[c2] << " " << sum[c2] << endl;
    return 0;
}