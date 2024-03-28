// 组合
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long res = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            c++;
            res += c;
        } else {
            c = 0;
        }
    }
    cout << res << endl;
    return 0;
}