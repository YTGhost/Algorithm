#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        vector<bool> t(n, false);
        for(int j = 0; j < n; j++) {
            if(a[j] == 0) {
                int cur = j - i;
                if(cur >= 0) {
                    t[cur] = true;
                }
            } else {
                int cur = j + i;
                if(cur < n) {
                    t[cur] = true;
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(!t[j]) sum++;
        }
        if(i == n) cout << sum << endl;
        else cout << sum << " ";
    }
    return 0;
}