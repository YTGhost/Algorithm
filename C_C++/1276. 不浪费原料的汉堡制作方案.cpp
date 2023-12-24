class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // 4x + 2y = tomatoSlices
        // x + y = cheeseSlices
        if(tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices * 2 || 4 * cheeseSlices < tomatoSlices) {
            return {};
        }
        int x = tomatoSlices / 2 - cheeseSlices;
        int y = 2 * cheeseSlices - tomatoSlices / 2;
        return {x, y};
    }
};