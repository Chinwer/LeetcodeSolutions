/*
 * 1042. Flower Planting With No Adjacent
 *
 * You have N gardens, labelled 1 to N. In each garden, you want to plant
 * one of 4 types of flowers.
 *
 * paths[i] = [x, y] describes the existence of a bidirectional path from
 * garden x to garden y.
 *
 * Also, there is no garden that has more than 3 paths coming into or leaving it.
 *
 * Your task is to choose a flower type for each garden such that, for any two
 * gardens connected by a path, they have different types of flowers.
 *
 * Return any such a choice as an array answer, where answer[i] is the
 * type of flower planted in the (i + 1)-th garden. The flower types are
 * denoted 1, 2, 3, or 4. It is guaranteed an answer exists.
 *
 * Note:
 *   - 1 <= N <= 10000
 *   - 0 <= paths.size <= 20000
 *   - No garden has 4 or more paths coming into or leaving it.
 *   - It is guaranteed an answer exists.
 */

#include "header.h"

class Solution {
    public:
        vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
            vector<vector<int>> table(N);
            for (auto &p : paths) {
                table[p[0] - 1].push_back(p[1] - 1);
                table[p[1] - 1].push_back(p[0] - 1);
            }
            vector<int> res(N);
            for (int i = 0; i < N; i++) {
                set<int> colors = { 1, 2, 3, 4 };
                for (int c : table[i]) {
                    colors.erase(res[c]);
                }
                res[i] = *colors.begin();
            }
            return res;
        }
};