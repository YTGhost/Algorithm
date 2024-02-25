class Solution {
public:
    int m[26];
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.length();
        long long resCnt = 0;
        int resChar;
        for(int i = 0; i < n; i++) {
            int time = i == 0 ? releaseTimes[i] : releaseTimes[i] - releaseTimes[i-1];
            if(time > resCnt) {
                resChar = keysPressed[i];
                resCnt = time;
            } else if(time == resCnt) {
                if(keysPressed[i] > resChar) resChar = keysPressed[i];
            }
        }
        return resChar;
    }
};