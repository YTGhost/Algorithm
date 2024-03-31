#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int res = 0x3f3f3f3f;
    for(int i = 0; i < 10; i++) {
        int cnt = 0;
        for(int j = 0; j < k; j++) {
            cnt += abs(nums[j] - i);
        }
        res = min(res, cnt);
        for(int j = k; j < n; j++) {
            cnt += abs(nums[j] - i);
            cnt -= abs(nums[j - k] - i);
            res = min(res, cnt);
        }
    }
    cout << res << endl;
    return 0;
}