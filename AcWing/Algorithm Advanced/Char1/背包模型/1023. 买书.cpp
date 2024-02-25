#include <iostream>

using namespace std;

const int N = 1010;

int f[N], v[5];

int main()
{
    int n;
    cin >> n;
    v[1] = 10, v[2] = 20, v[3] = 50, v[4] = 100;
    
    f[0] = 1;
    
    for(int i = 1; i <= 4; i++)
        for(int j = v[i]; j <= n; j++)
            f[j] += f[j-v[i]];
    cout << f[n] << endl;
    return 0;
}