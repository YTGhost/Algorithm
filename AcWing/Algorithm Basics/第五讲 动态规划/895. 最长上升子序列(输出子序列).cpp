#include <iostream>

using namespace std;

const int N = 1010;
int f[N], a[N], g[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        g[i] = 0;
        for(int j = 1; j < i; j++)
            if(a[j] < a[i])
                if(f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
    }
    
    int k = 1;
    for(int i = 1; i <= n; i++)
        if(f[k] < f[i])
            k = i;
    
    cout << f[k] << endl;
    
    for(int i = 0, len = f[k]; i < len; i++)
    {
        cout << a[k] << " ";
        k = g[k];
    }
    return 0;
}