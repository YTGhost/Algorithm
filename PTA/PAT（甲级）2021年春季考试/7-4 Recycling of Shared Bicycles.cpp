#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 210;
int g[N][N], dist[N];
int n, m;
bool st[N];
bool visit[N];
int total = 0;
vector<int> path;

void dijkstra(int& start)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;
    for(int i = 0; i < n - 1; i++) {
        int t = -1;
        for(int j = 0; j < n; j ++) {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        st[t] = true;
        for(int j = 0; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    int res = 0x3f3f3f3f, idx = -1;
    for(int i = 0; i < n; i++) {
        if(!visit[i] && dist[i] < res) {
            res = dist[i];
            idx = i;
        }
    }
    if(idx != -1) {
        visit[idx] = true;
        start = idx;
        path.push_back(idx);
        total += res;
    } else {
        start = -1;
    }
}

int main()
{
    cin >> n >> m;
    n++;
    memset(g, 0x3f, sizeof g);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int start = 0;
    path.push_back(0);
    visit[0] = true;
    for(int i = 0; i < n-1; i++) {
        if(start == -1) break;
        dijkstra(start);
    }
    printf("%d", path[0]);
    for(int i = 1; i < n; i++) {
        printf(" %d", path[i]);
    }
    cout << endl;
    if(path.size() != n) {
        bool isFrist = true;
        for(int i = 0; i < n; i++) {
            if(!visit[i]) {
                if(isFrist) printf("%d", i);
                else printf(" %d", i);
            }
        }
    } else {
        cout << total << endl;
    }
    return 0;
}