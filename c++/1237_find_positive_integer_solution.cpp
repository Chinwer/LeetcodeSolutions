/*
 * 1237. Find Positive Integer Solution for a Given Equation
 *
 * Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
 *
 * The function is constantly increasing, i.e.:
 *
 *   - f(x, y) < f(x + 1, y)
 *   - f(x, y) < f(x, y + 1)
 * The function interface is defined like this: 
 *
 * interface CustomFunction {
 * public:
     // Returns positive integer f(x, y) for any given positive integer x and y.
     int f(int x, int y);
 * };
 * For custom testing purposes you're given an integer function_id and a target z as input, where function_id represent one function from an secret internal list, on the examples you'll know only two functions from the list.  
 *
 * You may return the solutions in any order.
 *
 * Constraints:
 *
 * 1 <= function_id <= 9
 * 1 <= z <= 100
 * It's guaranteed that the solutions of f(x, y) == z will be on the range 1 <= x, y <= 1000
 * It's also guaranteed that f(x, y) will fit in 32 bit signed integer if 1 <= x, y <= 1000
 */

#include "header.h"

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class CustomFunction {
    public:
        int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x = 1, y = 1000;
        vector<vector<int>> res;
        while (x <= 1000 && y >= 1) {
            if (customfunction.f(x, y) < z) {
                x++;
            } else if (customfunction.f(x, y) > z) {
                y--;
            } else {
                res.push_back({ x, y });
                x++;
                y--;
            }
        }
        return res;
    }
};
