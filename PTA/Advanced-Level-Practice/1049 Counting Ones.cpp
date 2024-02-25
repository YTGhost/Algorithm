#include <iostream>
#include <vector>
using namespace std;

int calc(int n) {
    vector<int> nums;
    int res = 0;
    while(n) nums.push_back(n % 10), n /= 10;
    
    for(int i = nums.size()-1; i >= 0; i--) {
        int l = 0, r = 0, power = 1;
        for(int j = nums.size()-1; j > i; j--) l = l * 10 + nums[j];
        for(int j = i-1; j >= 0; j--) {
            r = r * 10 + nums[j];
            power *= 10;
        }
        
        if(nums[i] == 0) {
            res += l * power;
        } else if(nums[i] == 1) {
            res += l * power + r + 1;
        } else {
            res += (l + 1) * power;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << calc(n) << endl;
    return 0;
}