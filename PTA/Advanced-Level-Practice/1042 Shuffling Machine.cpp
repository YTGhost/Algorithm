#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
int a[N], b[N], c[N];

void print(int x)
{
    if(x <= 13) cout << 'S' << x;
    else if(x <= 26) cout << 'H' << x - 13;
    else if(x <= 39) cout << 'C' << x - 26;
    else if(x <= 52) cout << 'D' << x - 39;
    else if(x <= 54) cout << 'J' << x - 52;
}

int main()
{
    int k;
    cin >> k;
    
    for(int i = 1; i <= 54; i++) a[i] = i;
    for(int i = 1; i <= 54; i++) cin >> b[i];
    
    while(k--) {
        memcpy(c, a, sizeof c);
        for(int i = 1; i <= 54; i++) {
            a[b[i]] = c[i];
        }
    }
    for(int i = 1; i <= 54; i++) {
        print(a[i]);
        if(i != 54) cout << ' ';
    }
}