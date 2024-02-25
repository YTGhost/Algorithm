#include <iostream>
using namespace std;

const int N = 100010;
int a[N];
int h[N];

int main()
{
    int n, x, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
        h[x]++; 
    }
    for(int i = 0; i < n; i++) {
        if(h[a[i]] == 1) {
            res = a[i];
            break;
        }
    }
    if(res) cout << res << endl;
    else cout << "None" << endl;
    return 0;
}