#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    double res = 2;
    double t = 1;
    for(int i = 0; i < 3; i++) {
        cin >> a >> b >> c;
        if(a > b && a > c) {
            t *= a;
            printf("W ");
        } else if(b > a && b > c) {
            t *= b;
            printf("T ");
        } else {
            t *= c;
            printf("L ");
        }
    }
    t = t * 0.65 - 1;
    res *= t;
    printf("%.2lf\n", res);
    return 0;
}