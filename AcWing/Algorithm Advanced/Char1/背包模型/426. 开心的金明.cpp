#include <iostream>

using namespace std;

const int N = 30010;

int f[N], v[N], w[N];

int main()
{
    int n, m;
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int p;
        cin >> v[i] >> p;
        w[i] = v[i] * p;
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j-v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}