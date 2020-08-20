/*
 * 131. Palindrome Partitioning
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 */

#include "header.h"

class Solution {
    private:
        int n;
        string s;
        vector<vector<string>> res;

    public:
        vector<vector<string>> partition(string s) {
            this->s = s;
            this->n = s.size();
            vector<string> path;
            backtrack(0, path);
            return res;
        }

        void backtrack(int start, vector<string> &path) {
            if (start == n) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < n; i++) {
                if (!is_palindrome(start, i)) {
                    continue;
                }
                path.push_back(s.substr(start, i - start + 1));
                backtrack(i + 1, path);
                path.pop_back();
            }
        }

        bool is_palindrome(int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
};
