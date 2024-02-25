#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); i++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(1);
    return c;
}

bool check(vector<int> &a)
{
    int l = 0, r = a.size()-1;
    while(l < r) if(a[l++] != a[r--]) return false;
    return true;
}

int main()
{
    string n;
    vector<int> a;
    int k;
    cin >> n >> k;
    for(int i = n.length()-1; i >= 0; i--) a.push_back(n[i] - '0');
    int cnt = 0;
    while(!check(a) && cnt < k) {
        vector<int> b(a.rbegin(), a.rend());
        a = add(a, b);
        cnt++;
    }
    for(int i = a.size()-1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}