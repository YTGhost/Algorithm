#include <iostream>
using namespace std;

const int N = 1010;
double a[N], b[N], c[N];

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        double x;
        cin >> n >> x;
        a[n] = x;
    }
    cin >> k;
    while(k--)
    {
        int n;
        double x;
        cin >> n >> x;
        b[n] = x;
    }
    for(int i = 0; i < N; i++) c[i] = a[i] + b[i];
    int cnt = 0;
    for(int i = 0; i < N; i++)
        if(c[i]) cnt++;
    cout << cnt;
    for(int i = N - 1; i >= 0; i--)
        if(c[i]){
            cnt++;
            printf(" %d %.1lf", i, c[i]);
        }
    return 0;
}