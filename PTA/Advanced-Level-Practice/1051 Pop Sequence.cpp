#include <iostream>
#include <stack>
using namespace std;

const int N = 1000;
int m, n, k;
int a[N];

int main()
{
    cin >> m >> n >> k;
    while(k--) {
        bool flag = true;
        stack<int> stk;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int cnt = 1;
        int idx = 1;
        while(idx <= n) {
            if(stk.empty()) {
                stk.push(cnt);
                cnt++;
            } else {
                if(stk.top() != a[idx]) {
                    if(cnt > n) {
                        flag = false;
                        break;
                    } else {
                        if(stk.size() == m) {
                            flag = false;
                            break;
                        } else {
                            stk.push(cnt);
                            cnt++;
                        }
                    }
                } else {
                    stk.pop();
                    idx++;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

const int N = 1010;
int m, n, k;
int a[N];

bool check()
{
    stack<int> stk;
    for(int i = 1, j = 0; i <= n; i++) {
        stk.push(i);
        
        if(stk.size() > m) return false;
        
        while(stk.size() && stk.top() == a[j]) {
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}

int main()
{
    cin >> m >> n >> k;
    while(k--) {
        bool flag = true;
        stack<int> stk;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}