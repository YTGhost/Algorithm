#include <iostream>
#include <sstream>
using namespace std;

bool isPrime(int x) 
{
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    int l, k;
    cin >> l >> k;
    string num;
    cin >> num;
    int flag = false;
    for(int i = 0 ; i <= l-k; i++) {
        stringstream stream;
        string str = num.substr(i, k);
        stream << str;
        int n;
        stream >> n;
        if(isPrime(n)) {
            cout << str << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << "404" << endl;
    return 0;
}