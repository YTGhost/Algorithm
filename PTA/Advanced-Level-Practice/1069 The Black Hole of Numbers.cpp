#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get(int n) 
{
    int nums[4];
    for(int i = 0; i < 4; i++) {
        nums[i] = n % 10;
        n /= 10;
    }
    sort(nums, nums + 4);
    int a = 0;
    for(int i = 0; i < 4; i++) {
        a = a * 10 + nums[i];
    }
    reverse(nums, nums + 4);
    int b = 0;
    for(int i = 0; i < 4; i++) {
        b = b * 10 + nums[i];
    }
    return {b, a};
}

int main()
{
    int n;
    cin >> n;
    do {
        auto t = get(n);
        printf("%04d - %04d = %04d\n", t[0], t[1], t[0] - t[1]);
        n = t[0] - t[1];
    }while(n && n != 6174);
    return 0;
}