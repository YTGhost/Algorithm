#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], s;

void down(int x)
{
    int t = x;
    if(x*2 <= s && h[x*2] < h[t]) t = x*2;
    if(x*2+1 <= s && h[x*2+1] < h[t]) t = x*2+1;
    if(t != x)
    {
        swap(h[t], h[x]);
        down(t);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    s = n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    
    for(int i = n/2; i; i--) down(i);
    
    while(m--)
    {
        cout << h[1] << " ";
        h[1] = h[s];
        s--;
        down(1);
    }
    return 0;
}