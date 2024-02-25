#include <iostream>
using namespace std;

const int N = 105;
string a[N];

int main()
{
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) getline(cin, a[i]);
    
    for(int k = a[0].size(); k; k--) {
        string t = a[0].substr(a[0].length() - k);
        bool sign = true;
        for(int i = 1; i < n; i++) {
            if(k > a[i].length() || a[i].substr(a[i].length() - k) != t) {
                sign = false;
                break;
            }
        }
        if(sign) {
            cout << t << endl;
            return 0;
        }
    }
    cout << "nai" << endl;
    return 0;
}