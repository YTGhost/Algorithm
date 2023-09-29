class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for(int i = 0; i < m; i++) {
            if((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == m - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int i = -1;
        int size = flowerbed.size();
        while(i < size) {
            int j = i + 1;
            while(j < size && flowerbed[j] == 0) j++;
            int count = j - i;
            if(i == -1) count++;
            if(j == size) count++;
            sum += count / 2 - 1;
            if(sum >= size) return true;
            i = j;
        }
        return sum >= n;
    }
};