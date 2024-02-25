#include <iostream>

using namespace std;

const int N = 20010;

int f[N], v[N];

int main()
{
    int n, m;
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++) cin >> v[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j-v[i]] + v[i]);
    cout << m - f[m] << endl;
    return 0;
}