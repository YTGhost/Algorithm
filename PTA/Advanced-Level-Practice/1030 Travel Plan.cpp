// pre数组存路径
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 510;
int dist[N], g[N][N], w[N][N], sum[N];
int pre[N];
bool st[N];
int n, m, s, d;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
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
                sum[j] = sum[t] + w[t][j];
                pre[j] = t;
            } else if(dist[j] == dist[t] + g[t][j]) {
                if(sum[t] + w[t][j] < sum[j]) {
                    sum[j] = sum[t] + w[t][j];
                    pre[j] = t;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> d;
    memset(g, 0x3f, sizeof g);
    memset(w, 0x3f, sizeof w);
    while(m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = min(g[a][b], c);
        w[a][b] = w[b][a] = min(w[a][b], d);
    }
    
    dijkstra();
    
    vector<int> path;
    
    for(int i = d; i != s; i = pre[i]) path.push_back(i);
    
    cout << s;
    for(int i = path.size()-1; i >= 0; i--) {
        cout << " " << path[i];
    }
    printf(" %d %d", dist[d], sum[d]);
    return 0;
}

// paths存所有路径
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 510;
int dist[N], g[N][N], w[N][N], sum[N];
vector<vector<int>> paths(N);
bool st[N];
int n, m, s, d;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    for(int i = 0; i < n; i++) {
        paths[i].push_back(s);
    }
    
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
                sum[j] = sum[t] + w[t][j];
                paths[j] = paths[t];
                paths[j].push_back(j);
            } else if(dist[j] == dist[t] + g[t][j]) {
                if(sum[t] + w[t][j] < sum[j]) {
                    sum[j] = sum[t] + w[t][j];
                    paths[j] = paths[t];
                    paths[j].push_back(j);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> d;
    memset(g, 0x3f, sizeof g);
    memset(w, 0x3f, sizeof w);
    while(m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = min(g[a][b], c);
        w[a][b] = w[b][a] = min(w[a][b], d);
    }
    
    dijkstra();
    
    for(int i = 0; i < paths[d].size(); i++) {
        printf("%d ", paths[d][i]);
    }
    printf("%d %d", dist[d], sum[d]);
    return 0;
}