#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
string strs[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> strs[i];
    sort(strs, strs + n, [](string a, string b) {
        return a + b < b + a;
    });
    string res = "";
    for(int i = 0; i < n; i++) res += strs[i];
    int k = 0;
    while(k + 1 < res.size() && res[k] == '0') k++;
    res = res.substr(k);
    cout << res << endl;
    return 0;
}