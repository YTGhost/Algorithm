#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int a[N];
int st[N];
int n;

bool check(int num1, int num2)
{
    memset(st, 0, sizeof st);
    int cnt1 = 0, cnt2 = 0;
    st[num1] = 1, st[num2] = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0 && st[abs(a[i])] == 1 || a[i] < 0 && st[abs(a[i])] == 0) {
            if(st[i]) cnt2++;
            else cnt1++;
        }
    }
    return cnt1 == 1 && cnt2 == 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int res1, res2;
    bool flag = false;
    for(int i = 1; i <= n-1; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(check(i, j)) {
                res1 = i, res2 = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
        
    if(flag) cout << res1 << " " << res2 << endl;
    else cout << "No Solution" << endl;
    return 0;
}