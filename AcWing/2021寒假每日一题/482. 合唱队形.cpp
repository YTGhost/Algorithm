#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int a[N], f[N], n;

int main()
{
    int res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    
    for(int i = n-1; i >= 0; i--)
    {
        int t = f[i];
        f[i] = 1;
        for(int j = n-1; j > i; j--)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i] + t - 1);
    }
    cout << n - res << endl;
    return 0;
}