#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> a(305);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    for(int i = 0; i < n; i++)
    {
        int x = t[i];
        b[i] = x;
        if(a[x]) continue;
        while(x != 1)
        {
            if(x % 2 == 0) x /= 2;
            else x = (3 * x + 1) / 2;
            a[x] = 1;
        }
    }
    vector<int> res;
    for(int i = 0; i < n; i++)
        if(!a[b[i]]) res.emplace_back(b[i]);
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size()-1; i++)
        cout << res[i] << " ";
    cout << res[res.size()-1] << endl;
    return 0;
}