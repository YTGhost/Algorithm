#include <iostream>

using namespace std;

const int N = 1010;

int f[N], a[N];

int main()
{
    int n, ans = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++)
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
    }
    
    for(int i = n; i >= 1; i--)
    {
        int t = f[i];   // 保存登山时经过的景点数，就可以不用开两个数组了
        f[i] = 1;
        for(int j = n; j > i; j--)
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i] + t - 1);
    }
    
    cout << ans << endl;
    return 0;
}