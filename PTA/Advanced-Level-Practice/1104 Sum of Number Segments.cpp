#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long double res = 0;
    for(int i = 1; i <= n; i++) {
        long double x;
        cin >> x;
        res += x * i * (n - i + 1);
    }
    printf("%.2Lf", res);
    return 0;
}