#include <iostream>
using namespace std;
const int V = 30, N = 10010;

long long f[N];

int main()
{
    int v, n;
    cin >> v >> n;

    f[0] = 1;
    for(int i = 1; i <= v; i++)
    {
        int w;
        cin >> w;
        for(int j = w; j <= n; j++)
            f[j] += f[j-w];
    }
    cout << f[n] << endl;
    return 0;
}