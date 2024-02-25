#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    bool flag = true;
    for(int i = 0; i < n; i += m) {
        if(flag) {
            for(int j = i; j < n && j < i + m; j++) {
                if(j == i) printf("%d", a[j]);
                else printf(" %d", a[j]);
            }
            flag = false;
            cout << endl;
        } else {
            int t = min(n - 1, i + m - 1);
            for(int j = t; j >= i; j--) {
                if(j == t) printf("%d", a[j]);
                else printf(" %d", a[j]);
            }
            flag = true;
            cout << endl;
        }
    }
    return 0;
}