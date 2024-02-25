#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int g[N][N];
int d[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

queue<pair<int,int>> q;

int bfs()
{
    while(!q.empty())
    {
        pair t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push(pair(x, y));
            }
        }
    }
    
    return d[n-1][m-1];
}


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    q.push(pair(0,0));
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    cout << bfs() << endl;
    return 0; 
}