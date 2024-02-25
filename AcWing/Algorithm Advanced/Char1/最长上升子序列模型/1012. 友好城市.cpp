#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

typedef pair<int, int> PII;

int f[N];
PII a[N];

int main()
{
    int n, ans = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    
    sort(a + 1, a + n + 1); // 下标从1开始
    
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[j].second < a[i].second)
                f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
    }
    cout << ans << endl;
    return 0;
}