#include <iostream>
using namespace std;
typedef long long LL;

bool check(LL a, LL b, LL c) {
    LL d = a + b;
    if(a >= 0 && b >= 0 && d < 0) return true;
    if(a < 0 && b < 0 && d >= 0) return false;
    return a + b > c;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        LL a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if(check(a, b, c)) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}