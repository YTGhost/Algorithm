#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
int a[N];
int h[N];
int MSize, n;

bool check(int x)
{
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int find(int x) {
    int t = x % MSize;
    for(int k = 0; k < MSize; k++) {
        int i = (t + k * k) % MSize;
        if(!h[i]) {
            h[i] = x;
            return i;
        } 
    }
    return -1;
}

int main()
{
    cin >> MSize >> n;
    while(!check(MSize)) {
        MSize++;
    };
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto sign = find(x);
        if(sign == -1) {
            cout << "-";
        } else {
            cout << sign;
        }
        if(i != n-1) cout << " ";
    }
    return 0;
}