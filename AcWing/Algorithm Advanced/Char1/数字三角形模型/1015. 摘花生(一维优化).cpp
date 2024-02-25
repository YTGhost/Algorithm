#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int f[N], a[N][N];

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
                f[j] = max(f[j], f[j-1]) + a[i][j];
        
        cout << f[c] << endl;
        memset(f, 0, sizeof f);
    }
    return 0;
}