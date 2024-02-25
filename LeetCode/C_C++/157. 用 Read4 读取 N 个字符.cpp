/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int idx = 0;
        char temp[4];
        while(idx < n) {
            int cnt = read4(temp);
            if(cnt == 0) {
                break;
            }
            for(int i = 0; i < cnt; i++) {
                buf[idx + i] = temp[i];
            }
            idx += cnt;
        }
        return min(idx, n);
    }
};