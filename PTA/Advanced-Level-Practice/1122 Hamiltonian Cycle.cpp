#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int n, m;
int g[N][N];
int st[N];
int nodes[N * 2];

bool check(int cnt)
{
    memset(st, 0, sizeof st);
    if(nodes[0] != nodes[cnt-1] || cnt != n+1) return false;
    
    for(int i = 0; i < cnt-1; i++) {
        if(!g[nodes[i]][nodes[i+1]]) return false;
        st[nodes[i]] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!st[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    int k;
    cin >> k;
    while(k--) {
        int cnt;
        cin >> cnt;
        for(int i = 0; i < cnt; i++) cin >> nodes[i];
        bool flag = check(cnt);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}