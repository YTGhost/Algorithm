#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int h[N], e[N], ne[N], idx;
int cnt[N], max_depth;

void dfs(int id, int u)
{
    if(h[id] == -1) {
        cnt[u]++;
        max_depth = max(max_depth, u);
        return;
    }
    for(int i = h[id]; ~i; i = ne[i]) {
        dfs(e[i], u+1);
    }
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for(int i = 0; i < k; i++) {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    dfs(1, 0);
    cout << cnt[0];
    for(int i = 1; i <= max_depth; i++) {
        cout << " " << cnt[i];
    }
    cout << endl;
    return 0;
}