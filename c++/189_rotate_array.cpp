/*
 * 189. Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int cnt = 0;
            int start = 0;
            int tmp, curr, prev;
            int size = nums.size();
            k %= size;
            prev = nums[0];
            while (cnt < size) {
                curr = start++;
                do {
                    int next = (curr + k) % size;
                    tmp = nums[next];
                    nums[next] = prev;
                    prev = tmp;
                    curr = next;
                    cnt++;
                } while (curr != start);
            }
        }
};
