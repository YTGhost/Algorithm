#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b;

bool check(string str) {
    int l = 0, r = str.length()-1;
    while(l < r) {
        if(str[l++] != str[r--]) return false;
    }
    return true;
}

vector<int> add(vector<int> &a, vector<int> &b) {
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size() || i < b.size(); i++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(1);
    return c;
}

int main()
{
    string str;
    int count = 0;
    cin >> str;
    
    while(!check(str) && count < 10) {
        a.clear();
        b.clear();
        string num1;
        string num2;
        for(int i = 0, j = str.length()-1; i < str.length(); i++, j--) {
            a.push_back(str[j] - '0');
            b.push_back(str[i] - '0');
            num1 += str[j];
            num2 += str[i];
        }
        auto c = add(a, b);
        string t;
        for(int i = c.size()-1; i >= 0; i--) {
            t += to_string(c[i]);
        }
        str = t;
        cout << num2 << " + " << num1 << " = " << str << endl;
        count++;
    }
    if(count < 10) {
        cout << str << " is a palindromic number.";
    } else {
        printf("Not found in 10 iterations.");
    }
    return 0;
}