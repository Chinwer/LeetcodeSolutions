/*
 * 842. Split Array into Fibonacci Sequence
 *
 * Given a string S of digits, such as S = "123456579", we can split it
 * into a Fibonacci-like sequence [123, 456, 579].
 *
 * Formally, a Fibonacci-like sequence is a list F of non-negative
 * integers such that:
 *
 * 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed
 * integer type);
 * F.length >= 3;
 * and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 * Also, note that when splitting the string into pieces, each piece must
 * not have extra leading zeroes, except if the piece is the number 0 itself.
 *
 * Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.
 *
 * Note:
 *
 * 1 <= S.length <= 200
 * S contains only digits.
 */

#include "header.h"

class Solution {
    private:
        int n;
        vector<int> res;

    public:
        vector<int> splitIntoFibonacci(string S) {
            this->n = S.size();
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (backtrack(0, i, j, S)) {
                        return res;
                    }
                }
            }
            return res;
        }

        bool backtrack(int i, int j, int k, string &s) {
            if ((s[i] == '0' && j - i > 1) ||
                (s[j] == '0' && k - j > 1)) {
                return false;
            }

            string sub1 = s.substr(i, j - i);
            string sub2 = s.substr(j, k - j);
            string sub3 = add(sub1, sub2);
            int len = sub3.length();

            if (len > 10 || stol(sub3) >= INT_MAX) {
                return false;
            }

            if (k + len > n || sub3 != s.substr(k, len)) {
                return false;
            }

            res.push_back(stoi(sub1));
            if (k + len == n) {
                res.push_back(stoi(sub2));
                res.push_back(stoi(sub3));
                return true;
            }
            if (backtrack(j, k, k + len, s)) {
                return true;
            }
            res.pop_back();
            return false;
        }

        string add(string &a, string &b) {
            string res;
            int carry = 0;
            int i = a.size() - 1;
            int j = b.size() - 1;
            while (i >= 0 || j >= 0 || carry > 0) {
                int n1 = i >= 0 ? a[i--] - '0' : 0;
                int n2 = j >= 0 ? b[j--] - '0' : 0;
                res += (n1 + n2 + carry) % 10 + '0';
                carry = (n1 + n2 + carry) / 10;
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
