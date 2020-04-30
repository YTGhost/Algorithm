/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n;
        while(l < r)
        {
            long mid = l + r >> 1;
            if(guess(mid) == -1 || guess(mid) == 0) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};