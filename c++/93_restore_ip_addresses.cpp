/*
 * 93. Restore IP Addresses
 *
 * Given a string s containing only digits.
 * Return all possible valid IP addresses that can be obtained from s.
 * You can return them in any order.
 *
 * A valid IP address consists of exactly four integers, each integer is between 0 and 255,
 * separated by single points and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
 *
 * Constraints:
 *   - 0 <= s.length <= 3000
 *   - s consists of digits only
 */

#include "header.h"

class Solution {
    private:
        vector<string> res;

    public:
        vector<string> restoreIpAddresses(string s) {
            vector<int> dots;
            if (s.length() > 12) {
                return res;
            }
            backtrack(0, s, dots);
            return res;
        }

        void backtrack(int start, string &s, vector<int> &dots) {
            int n = s.size();
            if (dots.size() == 3) {
                string ip = get_ip(s, dots);
                if (is_valid_ip(s, dots)) {
                    res.push_back(ip);
                }
            } else {
                int end = min(n - 1, start + 4);
                for (int i = start; i < end; i++) {
                    dots.push_back(i + 1);
                    backtrack(i + 1, s, dots);
                    dots.pop_back();
                }
            }
        }

        string get_ip(string &s, vector<int> &dots) {
            string res = s;
            int n = dots.size();
            for (int i = 0; i < n; i++) {
                res.insert(dots[i] + i, ".");
            }
            return res;
        }

        bool is_valid_ip(string &s, vector<int> &dots) {
            int pos = 0, n = dots.size();
            for (int i = 0; i < n; i++) {
                string sub = s.substr(pos, dots[i] - pos);
                if (!is_valid_num(sub)) {
                    return false;
                }
                pos = dots[i];
            }
            return is_valid_num(s.substr(pos, s.size() - pos));
        }

        bool is_valid_num(string sub) {
            int n = sub.size();
            if (n > 3) {
                return false;
            }
            int num = stoi(sub);
            return num >= 0 && num < 256 &&
                (n == 1 || sub[0] != '0');
        }
};
