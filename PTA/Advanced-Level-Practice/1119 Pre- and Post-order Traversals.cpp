#include <iostream>
using namespace std;

const int N = 35;
int preorder[N], postorder[N];
int n;

int dfs(int l1, int r1, int l2, int r2, string &str)
{
    if(l1 > r1) return 1;
    if(preorder[l1] != postorder[r2]) return 0;
    
    int cnt = 0;
    for(int i = l1; i <= r1; i++) {
        string lstr, rstr;
        int lcnt = dfs(l1 + 1, i, l2, l2 + i - l1 - 1, lstr);
        int rcnt = dfs(i + 1, r1, l2 + i - l1 - 1 + 1, r2 - 1, rstr);
        
        if(lcnt && rcnt) {
            str = lstr + to_string(preorder[l1]) + " " + rstr;
            cnt += lcnt * rcnt;
            if(cnt > 1) break;
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> preorder[i];
    for(int i = 0; i < n; i++) cin >> postorder[i];
    
    string str;
    int cnt = dfs(0, n-1, 0, n-1, str);
    
    if(cnt == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    str.pop_back();
    cout << str << endl;
    return 0;
}