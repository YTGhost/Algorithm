#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;

int f[N][N];

int main()
{
    int n, m, v;
    cin >> v >> m >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for(int j = v; j >= a; j--)
            for(int k = m-1; k >= b; k--)
                f[j][k] = max(f[j][k], f[j-a][k-b] + 1);
    }
    cout << f[v][m-1] << " ";
    int k = m-1;
    while(k > 0 && f[v][k-1] == f[v][m-1]) k--;
    cout << m - k << endl;
    return 0;
}