#include <iostream>

using namespace std;

const int N = 110;

int f[N][N], a[N][N];

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                cin >> a[i][j];
        
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];
        
        cout << f[r][c] << endl;
    }
    return 0;
}