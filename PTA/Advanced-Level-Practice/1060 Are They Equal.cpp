#include <iostream>
using namespace std;

int n;
string a, b;

string change(string x, int n)
{
    int k = x.find(".");
    if(k == -1) x += ".", k = x.find(".");
    string s = x.substr(0, k) + x.substr(k + 1);
    while(s.size() && s[0] == '0') s = s.substr(1), k--;
    if(s.empty()) k = 0;
    if(s.size() > n) s = s.substr(0, n);
    else s += string(n - s.size(), '0');
    return "0." + s + "*10^" + to_string(k);
}

int main()
{
    cin >> n >> a >> b;
    
    string stra = change(a, n);
    string strb = change(b, n);
    
    if(stra == strb) {
        printf("YES ");
        cout << stra << endl;
    } else {
        printf("NO ");
        cout << stra << " " << strb << endl;
    }
    return 0;
}