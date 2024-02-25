#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int get(char c)
{
    if(c <= '9') return c - '0';
    return c - 'a' + 10;
}

LL calc(string n, LL r)
{
    LL res = 0;
    for(auto c : n) {
        if((double)res * r + get(c) > 1e16) return 1e18;
        res = res * r + get(c);
    }
    return res;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int tag, radix;
    cin >> tag >> radix;
    if(tag == 2) swap(n1, n2);
    LL target = calc(n1, radix);
    
    LL l = 0, r = target + 1;
    for(auto c : n2) l = max(l, (LL)get(c) + 1);
    
    while(l < r) {
        LL mid = l + r >> 1;
        if(calc(n2, mid) >= target) r = mid;
        else l = mid + 1;
    }
    if(calc(n2, l) != target) cout << "Impossible" << endl;
    else cout << l << endl;
    return 0;
}