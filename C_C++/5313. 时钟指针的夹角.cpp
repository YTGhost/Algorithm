class Solution {
public:
    double angleClock(int hour, int minutes) {
        int h[13] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 0};
        double b = minutes * 6;
        double a = h[hour] + 0.5 * minutes;
        if(a>b){
            return std::min(360-a+b, a-b);
        }else{
            return std::min(360-b+a, b-a);
        }
    }
};