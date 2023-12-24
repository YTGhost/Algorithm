class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int i = 1;
        while(1) {
            if((long long)2 * i * (i + 1) * (2 * i + 1) >= neededApples) {
                break;
            }
            i++;
        }
        return 8 * i;
    }
};
