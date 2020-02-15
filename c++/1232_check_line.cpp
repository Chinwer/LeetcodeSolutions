/*
 * 1232. Check If It Is a Straight Line
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
 * represents the coordinate of a point. Check if these points make a straight
 * line in the XY plane.
 *
 * Constraints:
 *
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates contains no duplicate point.
 *
 */

#include "header.h"

class Solution {
    public:
        bool checkStraightLine(vector<vector<int>>& coordinates) {
            double slope;
            int x0 = coordinates[0][0];
            int y0 = coordinates[0][1];
            int x1 = coordinates[1][0];
            int y1 = coordinates[1][1];
            int size = coordinates.size();

            if (x0 == x1) {
                for (auto point : coordinates) {
                    if (point[0] != x0) {
                        return false;
                    }
                }
                return true;
            }

            slope = (y1 - y0) / (x1 - x0);

            for (int i = 2; i < size; i++) {
                int x = coordinates[i][0];
                int y = coordinates[i][1];
                if ((double) (y - y0) / (x - x0) != slope) {
                    return false;
                }
            }
            return true;
        }
};
