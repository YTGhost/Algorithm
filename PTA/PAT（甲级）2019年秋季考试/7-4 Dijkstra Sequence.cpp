#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1010, M = 200010, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], idx, w[M];
int dist[N][N];
int isCount[N];
int path[N];
int st[N];
typedef pair<int, int> PII;

bool check(int start)
{
    for(int i = 1; i < n; i++) {
        if(dist[start][path[i]] < dist[start][path[i-1]]) {
            return false;
        }
    }
    return true;
}

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int start)
{
    memset(st, 0, sizeof st);
    memset(dist[start], 0x3f, sizeof dist[start]);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[start][start] = 0;
    q.push({0, start});
    while(q.size()) {
        auto item = q.top();
        q.pop();
        if(st[item.second]) continue;
        st[item.second] = 1;
        for(int i = h[item.second]; ~i; i = ne[i]) {
            int val = e[i];
            if(dist[start][val] > dist[start][item.second] + w[i]) {
                dist[start][val] = dist[start][item.second] + w[i];
                q.push({dist[start][val], val});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int k;
    cin >> k;
    while(k--) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> path[i];
        }
        int start = path[0], end = path[n - 1];
        // 以start为开头的最短路算过没
        if(isCount[start]) {
            if(check(start)) printf("Yes\n");
            else printf("No\n");
        } else {
            dijkstra(start);
            isCount[start] = 1;
            if(check(start)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}