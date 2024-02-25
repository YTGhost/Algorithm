#include <iostream>
using namespace std;

const int N = 100010;
int p[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }
    
    int res = 0;
    for(int i = 1; i < n;) {
        while(p[0]) swap(p[0], p[p[0]]), res++;
        while(i < n && p[i] == i) i++;
        if(i < n) swap(p[0], p[i]), res++;
    }
    cout << res << endl;
}