/*
 * 744. Find Smallest Letter Greater Than Target
 *
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target,
 * find the smallest element in the list that is larger than the given target.
 *
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 *
 * Note:
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique letters.
 * target is a lowercase letter.
 */

#include "header.h"

class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int size = letters.size();
            int left = 0, right = size - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (letters[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (right < 0 || right == size - 1) {
                return letters[0];
            }
            return letters[right];
        }
};
