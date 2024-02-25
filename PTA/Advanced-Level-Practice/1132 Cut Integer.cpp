#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int mid = str.length() / 2;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < str.length(); i++) c = c * 10 + str[i] - '0';
        for(int i = 0; i < mid; i++) a = a * 10 + str[i] - '0';
        for(int i = mid; i < str.length(); i++) b = b * 10 + str[i] - '0';
        if(a == 0 || b == 0) cout << "No" << endl;
        else {
            if(c % (a * b) == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}