#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n - 1);
        for(int i = 0; i < n - 1; i++) {
            cin >> nums[i];
        }
        vector<int> a(n);
        // a[0] = nums[0] + 1;
        // 需要设置一个大于nums中所有数的数
        a[0] = 505
        cout << a[0];
        for(int i = 1; i < n; i++) {
            cout << " ";
            a[i] = a[i - 1] + nums[i - 1];
            cout << a[i];
        }
        cout << endl;
    }
}