#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    int k = m - n + 1;
    int cntOne = 0;
    for(int i = 0; i < k; i++) {
        if(b[i] == '1') cntOne++;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') sum += k - cntOne;
        else sum += cntOne;
        if(b[k + i] == '1') cntOne++;
        if(b[i] == '1') cntOne--;
    }
    cout << sum << endl;
    return 0;
}