/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st = 0, end = n;

        while(st <= end){
            int mid = st + (end - st) / 2;
            int guess_result = guess(mid);

            if(guess_result < 0){
                end = mid - 1;
            } else if (guess_result > 0){
                st = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};