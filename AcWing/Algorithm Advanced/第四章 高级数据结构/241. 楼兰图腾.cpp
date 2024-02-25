#include <iostream>
#include <cstring>
using namespace std;

const int N = 200010;
int n;
int a[N];
int tr[N];
int Greater[N], Lower[N];

typedef long long LL;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        int y = a[i];
        Greater[i] = sum(n) - sum(y);
        Lower[i] = sum(y - 1);
        add(y, 1);
    }
    
    memset(tr, 0, sizeof(tr));
    
    LL res1 = 0, res2 = 0;
    for(int i = n; i; i--) {
        int y = a[i];
        res1 += Greater[i] * (LL)(sum(n) - sum(y));
        res2 += Lower[i] * (LL)(sum(y - 1));
        add(y, 1);
    }
    
    cout << res1 << " " << res2;
    return 0;
}