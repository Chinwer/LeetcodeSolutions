/*
 * 1286. Iterator for Combination
 *
 * Design an Iterator class, which has:
 *
 *  - A constructor that takes a string characters of sorted distinct
 *    lowercase English letters and a number combinationLength as arguments.
 *  - A function next() that returns the next combination of length
 *    combinationLength in lexicographical order.
 *  - A function hasNext() that returns True if and only if there exists
 *    a next combination.
 *
 * Constraints:
 *
 * 1 <= combinationLength <= characters.length <= 15
 * There will be at most 10^4 function calls per test.
 * It's guaranteed that all calls of the function next are valid.
 */

#include "header.h"

class CombinationIterator {
    private:
        int i = 0, n, k;
        vector<string> combs;

    public:
        CombinationIterator(string characters, int combinationLength) {
            this->k = combinationLength;
            this->n = characters.size();
            sort(characters.begin(), characters.end(), less<char>());
            string path;
            backtrack(0, characters, path);
        }

        void backtrack(int start, string &s, string &path) {
            if (path.size() == k) {
                combs.push_back(path);
                return;
            }
            for (int i = start; i < n; i++) {
                path.push_back(s[i]);
                backtrack(i + 1, s, path);
                path.pop_back();
            }
        }

        string next() {
            return combs[i++];
        }

        bool hasNext() {
            return i < combs.size();
        }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
