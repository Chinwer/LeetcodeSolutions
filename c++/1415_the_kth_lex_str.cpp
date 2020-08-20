/*
 * 1415. The k-th Lexicographical String of All Happy Strings of Length n
 *
 * A happy string is a string that:
 *
 * consists only of letters of the set ['a', 'b', 'c'].
 * s[i] != s[i + 1] for all values of i from 1 to s.length - 1
 * (string is 1-indexed).
 * For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy
 * strings and strings "aa", "baa" and "ababbc" are not happy strings.
 *
 * Given two integers n and k, consider a list of all happy strings of
 * length n sorted in lexicographical order.
 *
 * Return the kth string of this list or return an empty string if there
 * are less than k happy strings of length n.
 *
 * Constraints:
 *
 * 1 <= n <= 10
 * 1 <= k <= 100
 */

#include "header.h"

class Solution {
    private:
        vector<string> happy;

    public:
        string getHappyString(int n, int k) {
            string path;
            backtrack(n, path);
            return k > happy.size() ? "" : happy[k - 1];
        }

        void backtrack(int n, string &path) {
            int m = path.size();
            if (m == n) {
                happy.push_back(path);
                return;
            }
            string chs = "abc";
            for (char &ch : chs) {
                if (check(path, ch)) {
                    path.push_back(ch);
                    backtrack(n, path);
                    path.pop_back();
                }
            }
        }

        bool check(string &path, char ch) {
            if (path.empty()) {
                return true;
            }
            return path[path.size() - 1] != ch;
        }
};
