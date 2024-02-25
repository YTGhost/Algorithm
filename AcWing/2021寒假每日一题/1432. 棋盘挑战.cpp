#include <iostream>
#include <algorithm>
using namespace std;

const int N = 26;
int g[N][N], c[N], dg[N], udg[N];
int path[N];
int n, res;

void dfs(int x)
{
    if(x == n+1) {
        res++;
        if(res <= 3) {
            for(int i = 1; i <= n; i++)
                cout << path[i] << " ";
            cout << endl;
        }
        return;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!c[i] && !dg[x+i] && !udg[n+i-x])
        {
            c[i] = dg[x+i] = udg[n+i-x] = 1;
            g[x][i] = 'Q';
            path[x] = i;
            dfs(x+1);
            path[x] = 0;
            g[x][i] = '.';
            c[i] = dg[x+i] = udg[n+i-x] = 0;
        }
    }
    
}

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = '.';
    dfs(1);
    cout << res << endl;
    return 0;
}