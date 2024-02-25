#include <iostream>
using namespace std;

bool isPrimeDay = true;

bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    string n;
    cin >> n;
    while(n.length()) {
        printf("%s", n.c_str());
        int x = stoi(n);
        if(isPrime(x)) {
            printf(" Yes\n");
        } else {
            printf(" No\n");
            isPrimeDay = false;
        }
        n = n.substr(1);
    }
    if(isPrimeDay) printf("All Prime!\n");
    return 0;
}