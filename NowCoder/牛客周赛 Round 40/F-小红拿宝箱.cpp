#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> suffix(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    if(n <= 2) {
        cout << sum << endl;
        return 0;
    }
    for(int i = n - 1; i >= 0; i--) {
        suffix[i] = a[i] + suffix[i + 1];
    }
    // 平均期望
    double avg = sum * 2.0 / n;
    double res = 0;
    for(int i = 0; i < n; i++) {
        double temp = (sum - a[i]) / (n - 1);
        int idx = lower_bound(a.begin(), a.end(), temp) - a.begin();
        double E = suffix[idx] + temp * idx;
        if(a[i] >= temp) E -= a[i];
        else E -= temp;
        E /= n - 1;
        res += max(avg, E + a[i]);
    }
    
    printf("%.7f", res / n);
    return 0;
}