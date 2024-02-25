#include <iostream>
#include <algorithm>
using namespace std;
const int M = 10010;

int f[M];

int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for(int j = m; j >= a; j--)
            f[j] += f[j-a];
    }
    cout << f[m] << endl;
    return 0;
}