#include <iostream>
using namespace std;

int n, m;
const int N = 510;
bool g[N][N];
int d[N];
bool st[N];

int dfs(int x)
{
    st[x] = true;
    int res = 1;
    for(int i = 1; i <= n; i++) {
        if(!st[i] && g[x][i])
            res += dfs(i);
    }
    return res;
}

int check1()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(d[i] % 2)
            cnt++;
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
        d[a]++, d[b]++;
    }
    cout << d[1];
    for(int i = 2; i <= n; i++) {
        printf(" %d", d[i]);
    }
    cout << endl;
    int cnt = dfs(1);
    if(cnt == n) {
        int cnt = check1();
        if(cnt == 0) cout << "Eulerian" << endl;
        else if(cnt == 2) cout << "Semi-Eulerian" << endl;
        else cout << "Non-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }
}