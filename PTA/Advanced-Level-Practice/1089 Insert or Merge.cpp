#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
int n;
int a[N], b[N];

bool check()
{
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    int p = 2;
    while(p <= n && b[p] >= b[p-1]) p++;
    int k = p;
    while(p <= n && a[p] == b[p]) p++;
    if(p == n + 1) {
        cout << "Insertion Sort" << endl;
        while(k > 1 && b[k] < b[k-1]) swap(b[k], b[k-1]), k--;
        printf("%d", b[1]);
        for(int i = 2; i <= n; i++) printf(" %d", b[i]);
        cout << endl;
    } else {
        cout << "Merge Sort" << endl;
        int k = 1;
        while(true) {
            bool match = check();
            int len = 1 << k;
            for(int i = 1; i <= n; i += len) {
                sort(a + i, a + min(n + 1, i + len));
            }
            if(match) break;
            k++;
        }
        printf("%d", a[1]);
        for(int i = 2; i <= n; i++) printf(" %d", a[i]);
        cout << endl;
    }
    return 0;
}