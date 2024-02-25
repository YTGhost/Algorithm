#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int z, x, y;
};

const int M = 1286, N = 128, L = 60;
int m, n, l, t;
int g[L][M][N];
int d[][3] = {
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1}
};

int bfs(int i, int j, int k)
{
    queue<Node> q;
    q.push({i, j, k});
    g[i][j][k] = 0;
    int sum = 1;
    while(!q.empty()) {
        auto item = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            int z, x, y;
            z = item.z + d[i][0], x = item.x + d[i][1], y = item.y + d[i][2];
            if(z >= 0 && z < l && x >= 0 && x < m && y >= 0 && y < n && g[z][x][y]) {
                q.push({z, x, y});
                g[z][x][y] = 0;
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    cin >> m >> n >> l >> t;
    
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) {
                cin >> g[i][j][k];
            }
    
    int res = 0;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) {
                if(g[i][j][k]) {
                    int sum = bfs(i, j, k);
                    if(sum >= t) res += sum;
                }
            }
    cout << res << endl;
    return 0;
}