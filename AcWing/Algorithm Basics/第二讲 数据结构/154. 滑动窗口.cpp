#include <iostream>

using namespace std;

const int N = 1000010;

int q[N], a[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    // 输出滑动窗口最小值
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if(i >= k-1) printf("%d ", a[q[hh]]);
    }
    puts("");
    
    // 输出滑动窗口最大值
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if(i >= k-1) printf("%d ", a[q[hh]]);
    }
    puts("");
    
    return 0;
}