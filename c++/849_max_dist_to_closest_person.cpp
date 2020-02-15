/*
 * 849. Maximum Distance to Closest Person
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
 *
 * Return that maximum distance to closest person.
 *
 * Note:
 *
 * 1 <= seats.length <= 20000
 * seats contains only 0s or 1s, at least one 0, and at least one 1.
 */

#include "header.h"

class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int i = 0, j = 0;
            int size = seats.size();
            while (i < size) {
                if (seats[i]) {
                    break;
                }
                i++;
            }
            int res = i;
            for (j = i + 1; j < size; j++) {
                if (seats[j]) {
                    res = max(res, (j - i) / 2);
                    i = j;
                }
            }
            res = max(res, size - 1 - i);
            return res;
        }
};
