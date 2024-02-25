#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int N = 150010;
int n, m;
int h[N], e[N], ne[N], w[N], idx, dist[N];
bool st[N];
typedef pair<int, int> PII;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;  
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while(q.size()) {
        auto item = q.top();
        q.pop();
        if(st[item.second]) continue;
        st[item.second] = true;
        
        for(int i = h[item.second]; ~i; i = ne[i]) {
            auto node = e[i];
            if(dist[node] > dist[item.second] + w[i]) {
                dist[node] = dist[item.second] + w[i];
                q.push({dist[node], node});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int res = dijkstra();
    cout << res << endl;
    return 0;
}