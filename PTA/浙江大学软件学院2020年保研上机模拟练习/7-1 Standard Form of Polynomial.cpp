#include <iostream>
using namespace std;
const int N = 15;
int n;
int a[N];
int res[N];

inline void dfs(int x, int s, int limit)
{
    if(x > n) {
        res[limit] += s;
        return;
    }
    dfs(x + 1, s * a[x], limit - 1);
    dfs(x + 1, s, limit);
    return;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }
    dfs(1, 1, n);
    for(int i = n - 1; i > 0; i--) printf("%d ", res[i]);
    printf("%d", res[0]);
    return 0;
}