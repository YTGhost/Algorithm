#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 205;
queue<pair<int, int>> q;
char g[N][N];
int d[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs()
{
    int res = -1;
    while(!q.empty())
    {
        pair t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || d[x][y] != -1 || g[x][y] == '#')
                continue;
            d[x][y] = d[t.first][t.second] + 1;
            if(g[x][y] == 'E') {
                res = d[x][y];
                break;
            } 
            q.push(pair(x, y));
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(d, -1, sizeof d);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S') {
                    q.push(pair(i, j));
                    d[i][j] = 0;
                }
            }
        int res = bfs();
        if(res == -1) cout << "oop!" << endl;
        else cout << res << endl;
    }
    return 0;
}