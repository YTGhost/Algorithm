#include <iostream>
using namespace std;
const int N = 110;
int q[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for(int x = 0, y = 0, k = 1, d = 0; k <= n*m; k++)
    {
        q[x][y] = k;
        int a = x + dx[d], b = y + dy[d];
        if(a >= n || a < 0 || b >= m || b < 0 || q[a][b])
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << q[i][j] << " ";
        cout << endl;
    }
    return 0;
}