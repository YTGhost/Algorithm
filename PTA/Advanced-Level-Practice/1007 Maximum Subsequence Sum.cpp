#include <iostream>
using namespace std;

const int N = 10010;
int a[N];
int dp[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int res = -1, sum = -1, l, r;
    for(int i = 0, start = 0; i < n; i++)
    {
        if(sum < 0) sum = 0, start = i;
        sum += a[i];
        if(sum > res) {
            res = sum;
            l = a[start], r = a[i];
        }
    }
    if(res < 0) res = 0, l = a[0], r = a[n-1];
    cout << res << " " << l << " " << r << endl;
    return 0;
}