#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int h[N];

int main()
{
    int res = 1e6;
    int n;
    cin >> n;
    for(int i; i < n; i++) cin >> h[i];
    
    for(int i = 0; i + 17 <= 100; i++)
    {
        int cost = 0, l = i, r = i+17;
        for(int i = 0; i < n; i++)
            if(h[i] < l) cost += (l - h[i]) * (l - h[i]);
            else if(h[i] > r) cost += (h[i] - r) * (h[i] - r);
        res = min(res, cost);
    }
    cout << res << endl;
    return 0;
}