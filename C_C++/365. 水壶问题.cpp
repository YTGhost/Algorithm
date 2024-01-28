class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if(jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == 0;
        }
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)   return false;
        if(x == 0 || y == 0)    return z == 0 || x + y == z;
        return z % gcd(x,y) == 0;
    }
};