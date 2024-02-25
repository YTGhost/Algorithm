#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 1, c = 1;
    int last;
    while(c < n) {
        last = c;
        c = a + b;
        a = b;
        b = c;
    }
    int diff1 = n - last;
    int diff2 = c - n;
    if(diff2 < diff1) printf("%d", c);
    else printf("%d", last);
    return 0;
}