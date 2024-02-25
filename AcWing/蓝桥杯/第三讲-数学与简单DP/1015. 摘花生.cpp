#include <iostream>
using namespace std;

const int N = 105;
int a[N][N];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                a[i][j] = max(a[i-1][j], a[i][j-1]) + a[i][j];
        cout << a[n][m] << endl;
    }
    return 0;
}