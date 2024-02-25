#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N];

int main()
{
    int n, res = 0;
    cin >> n;
    
    if(n >= 3) {
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i < n-1; i++)
            if(a[i-1] < a[i] && a[i] > a[i+1] || a[i-1] > a[i] && a[i+1] > a[i])
                res++;
    }
    cout << res << endl;
    return 0;
}