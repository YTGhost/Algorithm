#include <iostream>
using namespace std;

char get(int x)
{
    if(x <= 9) return '0' + x;
    return 'A' + x - 10;
}

int main()
{
    int x;
    printf("#");
    for(int i = 0; i < 3; i++) {
        cin >> x;
        if(x < 13) {
            printf("0%c", get(x));
        } else {
            char a = get(x / 13);
            char b = get(x % 13);
            printf("%c%c", a, b);
        }
    }
    return 0;
}