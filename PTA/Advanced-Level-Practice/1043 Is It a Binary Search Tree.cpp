#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int preorder[N], inorder[N], postorder[N], cnt;

bool build(int il, int ir, int pl, int pr, int type)
{
    if(il > ir) return true;
    
    int root = preorder[pl];
    int k;
    if(type == 0) {
        for(k = il; k <= ir; k++) {
            if(inorder[k] == root) {
                break;
            }
        }
        if(k > ir) return false;
    } else {
        for(k = ir; k >= il; k--) {
            if(inorder[k] == root) {
                break;
            }
        }
        if(k < il) return false;
    }
    
    bool res = true;
    if(!build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), type)) res = false;
    if(!build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, type)) res = false;
    
    postorder[cnt++] = root;
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
        inorder[i] = preorder[i];
    }
    
    sort(inorder, inorder + n);
    
    if(build(0, n - 1, 0, n - 1, 0)) {
        cout << "YES" << endl;
        cout << postorder[0];
        for(int i = 1; i < n; i++) {
            cout << " " << postorder[i];
        }
        cout << endl;
    } else {
        cnt = 0;
        reverse(inorder, inorder + n);
        if(build(0, n - 1, 0, n - 1, 1)) {
            cout << "YES" << endl;
            cout << postorder[0];
            for(int i = 1; i < n; i++) {
                cout << " " << postorder[i];
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}