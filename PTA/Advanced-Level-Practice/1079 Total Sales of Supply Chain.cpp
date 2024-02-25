#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100010;
int n;
double P, R;
int p[N], f[N], cnt[N];

int dfs(int u)
{
    if(f[u] != -1) return f[u];
    if(p[u] == -1) return 0;
    return f[u] = dfs(p[u]) + 1;
}

int main()
{
    cin >> n >> P >> R;
    memset(f, -1, sizeof f);
    memset(p, -1, sizeof p);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            p[x] = i;
        }
        if(k == 0) {
            int c;
            cin >> c;
            cnt[i] = c;
        }
    }
    
    double res = 0;
    for(int i = 0; i < n; i++) {
        if(cnt[i]) {
            res += cnt[i] * P * pow(1 + R / 100, dfs(i));
        }
    }
    printf("%.1lf", res);
    return 0;
}