#include <iostream>
using namespace std;
const int N = 25;
char p[N][N];
int w, h;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int res;

void dfs(int a, int b)
{
    if(a < 0 || a >= h || b < 0 || b >= w || p[a][b] == '#' || p[a][b] == '$')
        return;
    p[a][b] = '$';
    res++;
    for(int i = 0; i < 4; i++)
        dfs(a + dx[i], b + dy[i]);
}

int main()
{
    while(cin >> w >> h && w && h)
    {
        int a, b;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
            {
                cin >> p[i][j];
                if(p[i][j] == '@')
                    a = i, b = j;
            }
        
        dfs(a, b);
        cout << res << endl;
        res = 0;
    }
    return 0;
}