#include <iostream>
using namespace std;

const int N = 105;
int a[N], b[N];

void down(int u, int size)
{
    int t = u;
    if(u * 2 <= size && b[t] < b[u * 2]) t = u * 2;
    if(u * 2 + 1 <= size && b[t] < b[u * 2 + 1]) t = u * 2 + 1;
    if(u != t) {
        swap(b[t], b[u]);
        down(t, size);
    }
}

int main()
{
    int n;
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
    } else {
        cout << "Heap Sort" << endl;
        p = n;
        while(b[p] >= b[1]) p--;
        swap(b[p], b[1]);
        down(1, p-1);
    }
    printf("%d", b[1]);
    for(int i = 2; i <= n; i++) printf(" %d", b[i]);
    cout << endl;
    return 0;
}