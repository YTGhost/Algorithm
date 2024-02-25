#include <iostream>
using namespace std;

int n, m;
const int N = 100010;
int l[N];

bool check(double length)
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        num += l[i] / length;
        if(num >= m) return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> l[i];
    
    double l = 0, r = 1e9;
    while(r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", l);
    return 0;
}