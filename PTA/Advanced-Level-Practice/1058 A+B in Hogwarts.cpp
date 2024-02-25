#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    int g, s, k;
    scanf("%d.%d.%d", &a, &b, &c);
    scanf("%d.%d.%d", &d, &e, &f);
    
    int t = 0;
    t += c + f;
    k = t % 29;
    t /= 29;
    t += b + e;
    s = t % 17;
    t /= 17;
    t += a + d;
    g = t;
    printf("%d.%d.%d", g, s, k);
    return 0;
}