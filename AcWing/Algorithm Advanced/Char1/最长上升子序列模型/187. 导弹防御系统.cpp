#include <iostream>

using namespace std;

const int N = 55;

int f[N], a[N], up[N], down[N], ans, n;

void dfs(int u, int su, int sd)
{
    if(su + sd >= ans) return;
    if(u == n){
        ans = su + sd;
        return;
    }
    
    // 情况1:将当前数放到上升序列中
    int k = 0;
    while(k < su && up[k] >= a[u]) k++;
    int t = up[k];
    up[k] = a[u];
    if(k < su) dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = t;
    
    // 情况2:将当前数放到下降序列中
    k = 0;
    while(k < sd && down[k] <= a[u]) k++;
    t = down[k];
    down[k] = a[u];
    if(k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main()
{
    while(cin >> n, n)
    {
        ans = n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        dfs(0, 0, 0);
        
        cout << ans << endl;
    }
    
    return 0;
}