#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 105;
int l[N], r[N];
int nodes[N], w[N];

void dfs(int u, int &k)
{
    if(u == -1) return;
    
    dfs(l[u], k);
    w[u] = nodes[k++];
    dfs(r[u], k);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    bool flag = false;
    while(!q.empty()) {
        int root = q.front();
        q.pop();
        if(flag) cout << " " << w[root];
        else {
            cout << w[root];
            flag = true;
        }
        if(l[root] != -1) q.push(l[root]);
        if(r[root] != -1) q.push(r[root]);
    }
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        l[i] = a, r[i] = b;
    }
    for(int i = 0; i < n; i++) cin >> nodes[i];
    sort(nodes, nodes + n);
    
    int k = 0;
    dfs(0, k);
    bfs(0);
    return 0;
}