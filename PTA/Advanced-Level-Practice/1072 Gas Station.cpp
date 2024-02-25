#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1020, M = 100000010, INF = 0x3f3f3f3f;
int h[N], ne[M], e[M], idx, w[M];
int n, m, k, d;
int dist[N];
int st[N];
double resAverDist = 0x3f3f3f3f;
int resIdx = -1, resMinDist = -1; 
typedef pair<int, int> PII;

void dijkstra(int start)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    while(q.size()) {
        auto item = q.top();
        q.pop();
        if(st[item.second]) continue;
        st[item.second] = 1;
        for(int i = h[item.second]; ~i; i = ne[i]) {
            int val = e[i];
            if(dist[val] > dist[item.second] + w[i]) {
                dist[val] = dist[item.second] + w[i];
                q.push({dist[val], val});
            }
        }
    }
    bool flag = true;
    int totalDist = 0, minDist = INF, minIdx;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF || dist[i] > d) {
            flag = false;
            break;
        } else {
            totalDist += dist[i];
            if(dist[i] < minDist) {
                minDist = dist[i];
                minIdx = i;
            }
        }
    }
    if(flag) {
        double averageDist = totalDist * 1.0 / n;
        if(minDist > resMinDist) {
            resAverDist = averageDist;
            resMinDist = minDist;
            resIdx = start - 1000;
        } else if(minDist == resMinDist) {
            if(averageDist < resAverDist) {
                resAverDist = averageDist;
                resMinDist = minDist;
                resIdx = start - 1000;
            }
        }
    }
}

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int main()
{
    cin >> n >> m >> k >> d;
    memset(h, -1, sizeof h);
    while(k--) {
        string a, b;
        int p1, p2, c;
        cin >> a >> b >> c;
        if(a[0] == 'G') p1 = 1000 + stoi(a.substr(1));
        else p1 = stoi(a);
        if(b[0] == 'G') p2 = 1000 + stoi(b.substr(1));
        else p2 = stoi(b);
        add(p1, p2, c);
        add(p2, p1, c);
    }
    for(int i = 1; i <= m; i++) {
        int val = 1000 + i;
        dijkstra(val);
    }
    if(resAverDist == INF) printf("No Solution\n");
    else {
        printf("G%d\n", resIdx);
        printf("%.1lf %.1lf\n", (double)resMinDist, round(resAverDist * 10) / 10);
    }
    return 0;
}