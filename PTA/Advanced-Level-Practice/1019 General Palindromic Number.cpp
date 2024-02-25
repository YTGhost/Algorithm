#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &res)
{
    int l = 0, r = res.size() - 1;
    while(l < r) {
        if(res[l++] != res[r--]) return false;
    }
    return true;
}

int main()
{
    vector<int> res;
    int n, b;
    cin >> n >> b;
    if(n == 0) res.push_back(0);
    else {
        while(n) {
            res.push_back(n % b);
            n /= b;
        }
    }
    bool t = check(res);
    if(t) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = res.size()-1; i >= 0; i--) {
        if(i == 0) printf("%d", res[i]);
        else printf("%d ", res[i]);
    }
    return 0;
}