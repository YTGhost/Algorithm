/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    char temp[4];
    int tempIdx = 0;
    int cnt = 0;
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;
        if(cnt > 0) {
            while(bufIdx < n && tempIdx < cnt) {
                buf[bufIdx++] = temp[tempIdx++];
            }
        }
        if(tempIdx == cnt) {
            tempIdx = 0;
            cnt = 0;
        }
        while(bufIdx < n) {
            cnt = read4(temp);
            if(cnt == 0) {
                break;
            }
            while(bufIdx < n && tempIdx < cnt) {
                buf[bufIdx++] = temp[tempIdx++];
            }
            if(tempIdx == cnt) {
                tempIdx = 0;
                cnt = 0;
            }
        }
        return bufIdx;
    }
};