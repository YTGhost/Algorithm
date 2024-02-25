#include <iostream>
using namespace std;

const int N = 10010;
int n;
int a[N];
int pre[N], post[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i-1]) pre[i] = pre[i-1] + 1;
        else if(a[i] == a[i-1]) pre[i] = pre[i-1];
        else pre[i] = 0;
    }
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] > a[i + 1]) post[i] = post[i + 1] + 1;
        else if(a[i] == a[i + 1]) post[i] = post[i + 1];
        else post[i] = 0;
    }
    int res = 200 * n;
    for(int i = 1; i <= n; i++) {
        res += max(pre[i], post[i]) * 100;
    }
    cout << res << endl;
    return 0;
}