#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 35;
int preorder[N], inorder[N];
unordered_map<int, int> pos;
bool res;

int build(int il, int ir, int pl, int pr, int& sum)
{
    int root = preorder[pl];
    int k = pos[abs(root)];
    if(k < il || k > ir) {
        res = false;
        return 0;
    }
    int l = 0, r = 0, ls = 0, rs = 0;
    if(il < k) l = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, ls);
    if(ir > k) r = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, rs);
    
    if(ls != rs) res = false;
    sum = ls;
    if(root < 0) {
        if(l < 0 || r < 0) res = false;
    } else {
        sum++;
    }
    return root;
}

int main()
{
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> preorder[i];
            inorder[i] = abs(preorder[i]);
        }
        pos.clear();
        sort(inorder, inorder + n);
        for(int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        res = true;
        int sum;
        int root = build(0, n-1, 0, n-1, sum);
        if(root < 0) res = false;
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}