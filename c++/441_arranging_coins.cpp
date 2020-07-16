/*
 * 441. Arranging Coins
 *
 * You have a total of n coins that you want to form in a staricase shape,
 * where every k-th row must have exactly k coins.
 *
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 */

class Solution {
    public:
        int arrangeCoins(int n) {
            // int i = 1;
            // long sum = 0;
            // while (sum < n) {
            //     sum += i++;
            // }
            // return sum == n ? i - 1 : i - 2;

            int low = 0, high = n;
            while (low <= high) {
                long mid = low + (high - low) / 2;
                long sum = mid * (mid + 1) / 2;
                if (sum == n) {
                    return mid;
                } else if (sum < n) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return high;
        }
};
