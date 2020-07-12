/*
 * 845. Longest Mountain in Array
 *
 * Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

 * - B.length >= 3
 * - There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 *
 * (Note that B could be any subarray of A, including the entire array A.)

 * Given an array A of integers, return the length of the longest mountain. 

 * Return 0 if there is no mountain.
 *
 * Note:

 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 * Follow up:

 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 */

#include "header.h"

class Solution {
public:
    int longestMountain(vector<int>& A) {
        // [2, 1, 4, 7, 3, 2, 5]
        // [2, 2, 2]
        int slow = 0, fast = 0;
        int res = 0, size = A.size();
        while (fast < size - 1) {
            bool found = false;
            while (slow < size - 1 && A[slow] >= A[slow + 1]) {
                slow++;
            }
            fast = slow;
            while (fast < size - 1 && A[fast] < A[fast + 1]) {
                fast++;
            }
            while (fast < size - 1 && A[fast] > A[fast + 1]) {
                found = true;
                fast++;
            }
            if (found) {
                res = max(res, fast - slow + 1);
            }
            slow = fast;
        }
        return res;
    }
};
