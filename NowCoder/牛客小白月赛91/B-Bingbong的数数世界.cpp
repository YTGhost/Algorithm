#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 4) cout << "Bing" << endl;
        else cout << "Bong" << endl;
    }
    return 0;
}