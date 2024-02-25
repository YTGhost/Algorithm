#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30010;

int f[N];

int main()
{
    int n, m;
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        w *= v;
        for(int j = m; j >= v; j--)
            f[j] = max(f[j], f[j-v] + w);
    }
    cout << f[m] << endl;
    return 0;
}