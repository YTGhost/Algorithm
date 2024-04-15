#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int x, y;
    char direct;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'W' || g[i][j] == 'S' || g[i][j] == 'A' || g[i][j] == 'D') {
                x = i, y = j;
                direct = g[i][j];
            }
        }
    }
    int res = 0;
    if(direct == 'W') {
        for(int i = x; i >= 0; i--) {
            if(g[i][y] == '*') res++;
        }
    } else if(direct == 'S') {
        for(int i = x; i < n; i++) {
            if(g[i][y] == '*') res++;
        }
    } else if(direct == 'A') {
        for(int i = y; i >= 0; i--) {
            if(g[x][i] == '*') res++;
        }
    } else if(direct == 'D') {
        for(int i = y; i < m; i++) {
            if(g[x][i] == '*') res++;
        }
    }
    cout << res << endl;
    return 0;
}