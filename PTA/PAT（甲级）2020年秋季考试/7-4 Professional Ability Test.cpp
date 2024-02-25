#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1010, M = 1000010;
int h[N], e[M], ne[M], w[M], v[M], idx, d[N], cd[N];
int dist[N], value[N], pre[N];
int n, m, k;
bool st[N];
typedef pair<int, int> PII;

void add(int a, int b, int c, int d)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, v[idx] = d, h[a] = idx++;
}

bool topsort()
{
    queue<int> q;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!d[i]) q.push(i), cnt++;
    }
    while(q.size()) {
        int t = q.front();
        q.pop();
        for(int i = h[t]; ~i; i = ne[i]) {
            int val = e[i];
            if(--d[val] == 0) q.push(val), cnt++;
        }
    }
    return cnt != n;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(value, 0, sizeof value);
    dist[n] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, n});
    while(q.size()) {
        auto item = q.top();
        q.pop();
        
        if(st[item.second]) continue;
        st[item.second] = true;
        
        for(int i = h[item.second]; ~i; i = ne[i]) {
            int val = e[i];
            if(dist[val] > dist[item.second] + w[i]) {
                dist[val] = dist[item.second] + w[i];
                value[val] = value[item.second] + v[i];
                pre[val] = item.second;
                q.push({dist[val], val});
            } else if(dist[val] == dist[item.second] + w[i]) {
                if(value[val] < value[item.second] + v[i]) {
                    value[val] = value[item.second] + v[i];
                    pre[val] = item.second;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a, b, score, v;
        cin >> a >> b >> score >> v;
        add(a, b, score, v);
        d[b]++;
    }
    memcpy(cd, d, sizeof d);
    
    bool isCircle = topsort();
    if(isCircle) printf("Impossible.\n");
    else {
        printf("Okay.\n");
        for(int i = 0; i < n; i++) {
            if(!cd[i]) add(n, i, 0, 0);
        }
        dijkstra();
    }
    
    cin >> k;
    while(k--) {
        int x;
        cin >> x;
        if(isCircle) {
            if(!cd[x]) printf("You may take test %d directly.\n", x);
            else printf("Error.\n");
        } else {
            if(!cd[x]) printf("You may take test %d directly.\n", x);
            else {
                vector<int> path;
                for(int i = x; i != n; i = pre[i]) path.push_back(i);
                printf("%d", path[path.size() - 1]);
                for(int i = path.size() - 2; i >= 0; i--) printf("->%d", path[i]);
                cout << endl;
            }
        }
    }
    return 0;
}