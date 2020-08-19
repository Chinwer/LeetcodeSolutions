/*
 * 面试题 08.09. Bracket LCCI
 *
 * Implement an algorithm to print all valid (e.g., properly opened and
 * closed combinations of n pairs of parentheses).
 *
 * Note: The result set should not contain duplicated subsets.
 *
 * For example, given n = 3, the result should be:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

#include "header.h"

// class Solution {
//     private:
//         vector<string> res;

//     public:
//         vector<string> generateParenthesis(int n) {
//             string paren;
//             backtrack(n, paren);
//             return res;
//         }

//         void backtrack(int n, string &paren) {
//             if (paren.size() == 2 * n) {
//                 if (valid(n, paren)) {
//                     res.push_back(paren);
//                 }
//             } else {
//                 paren.push_back('(');
//                 backtrack(n, paren);
//                 paren.pop_back();
//                 paren.push_back(')');
//                 backtrack(n, paren);
//                 paren.pop_back();
//             }
//         }

//         bool valid(int n, string &paren) {
//             int cnt = 0;
//             stack<char> s;
//             for (char p : paren) {
//                 if (s.empty()) {
//                     if (p == ')') {
//                         return false;
//                     }
//                     s.push(p);
//                 } else {
//                     if (p == ')' && s.top() == '(') {
//                         s.pop();
//                         continue;
//                     }
//                     s.push(p);
//                 }
//             }
//             return s.empty();
//         }
// };

class Solution {
    private:
        int n;
        vector<string> res;

    public:
        vector<string> generateParenthesis(int n) {
            this->n = n;
            string p;
            dfs(0, 0, p);
            return res;
        }

        void dfs(int lcnt, int rcnt, string &p) {
            if (lcnt == n && rcnt == n) {
                res.push_back(p);
                return;
            }
            if (lcnt + 1 <= n) {
                p.push_back('(');
                dfs(lcnt + 1, rcnt, p);
                p.pop_back();
            }
            if (rcnt + 1 <= lcnt) {
                p.push_back(')');
                dfs(lcnt, rcnt + 1, p);
                p.pop_back();
            }
        }
};
