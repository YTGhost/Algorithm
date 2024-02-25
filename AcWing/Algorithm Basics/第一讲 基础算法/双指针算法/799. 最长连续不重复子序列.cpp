#include <iostream>
using namespace std;

const int N = 100010;
int a[N], st[N];
int n, res;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0, j = 0; i < n; i++) {
        st[a[i]]++;
        while(j < i && st[a[i]] > 1) st[a[j++]]--;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}