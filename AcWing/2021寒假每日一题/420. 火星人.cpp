#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    // 偷懒做法可调用m次next_permutation即可
    while(m--)
    {
        int k = n-2;
        while(a[k] > a[k+1]) k--;
        int t = k + 1;
        while(t + 1 < n && a[t+1] > a[k]) t++;
        swap(a[k], a[t]);
        reverse(a + k + 1, a + n);
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

