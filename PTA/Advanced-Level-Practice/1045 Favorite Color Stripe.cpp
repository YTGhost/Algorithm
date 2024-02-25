#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[210], b[N], f[210][N];

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    int l;
    cin >> l;
    for(int i = 1; i <= l; i++) cin >> b[i];
    
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= l; j++)
        {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i][j-1] + 1);
        }
    cout << f[m][l] << endl;
    return 0;
}