/*
 * 22. Generate Parentheses
 *
 * Given n pairs of parentheses, wreite a function to generate all combinations
 * of well-formed parentheses.
 */

#include "header.h"

class Solution {
    private:
        vector<string> res;

    public:
        vector<string> generateParenthesis(int n) {
            string path;
            dfs(0, 0, n, path);
            return res;
        }

        void dfs(int l, int r, int n, string &path) {
            if (l == n && r == n) {
                res.push_back(path);
                return;
            }
            if (l + 1 <= n) {
                path.push_back('(');
                dfs(l + 1, r, n, path);
                path.pop_back();
            }
            if (r + 1 <= l) {
                path.push_back(')');
                dfs(l, r + 1, n, path);
                path.pop_back();
            }
        }
};
