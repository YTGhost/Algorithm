#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int total1 = 0, total2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            total1++;
        } else {
            total2++;
        }
    }
    int res = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            cnt1++;
        } else {
            cnt2++;
        }
        if(abs(cnt1 - cnt2) == abs(total1 - cnt1 - total2 + cnt2)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}