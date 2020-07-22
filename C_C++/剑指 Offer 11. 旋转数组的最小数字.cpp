class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size() - 1;
        while(n > 0 && numbers[n] == numbers[0]) n--;
        if(numbers[n] >= numbers[0]) return numbers[0];
        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(numbers[mid] < numbers[0]) r = mid;
            else l = mid + 1;
        }
        return numbers[l];
    }
};