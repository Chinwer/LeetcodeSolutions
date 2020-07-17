/*
 * 367. Valid Perfect Square
 *
 * Given a positive integer num, write a function which returns True
 * if num is a perfect square else False.
 *
 * Follow up:
 * Do not use any built-in library function such as sqrt.
 *
 * Constraints:
 *   - 1 <= num <= 2^31 - 1
 */

class Solution {
    public:
        bool isPerfectSquare(int num) {
            if (num < 3) {
                return num == 1;
            }
            int left = 0, right = num - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                double div = (double) num / mid;
                if (div == mid) {
                    return true;
                } else if (div < mid) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return false;
        }
};
