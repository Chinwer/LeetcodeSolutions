/*
 * 67. Add Binary
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 */

#include <string>
using namespace std;

int max(int a, int b);

class Solution {
    public:
        string addBinary(string a, string b) {
            // int carry = 0;
            // int lena = a.length();
            // int lenb = b.length();
            // int i = lena - 1;
            // int j = lenb - 1;
            // int len = max(lena, lenb);
            // int idx = len - 1;
            // string res(len, '0');

            // while (i >= 0 && j >= 0) {
            //     int tmp = a[i] - '0' + b[j] - '0' + carry;
            //     if (tmp > 1) {
            //         tmp %= 2;
            //         carry = 1;
            //     } else {
            //         carry = 0;
            //     }
            //     res[idx--] = tmp + '0';
            //     i--;
            //     j--;
            // }
            // while (i >= 0) {
            //     int tmp = (a[i] - '0' + carry) % 2;
            //     res[idx--] = tmp + '0';
            //     if (a[i] == '1' && carry == 1) {
            //         carry = 1;
            //     } else {
            //         carry = 0;
            //     }
            //     i--;
            // }
            // while (j >= 0) {
            //     int tmp = (b[j] - '0' + carry) % 2;
            //     res[idx--] = tmp + '0';
            //     if (b[j] == '1' && carry == 1) {
            //         carry = 1;
            //     } else {
            //         carry = 0;
            //     }
            //     j--;
            // }
            // if (carry == 1) {
            //     res.insert(0, "1");
            // }
            // res.erase(0, res.find_first_not_of('0'));
            // if (res.empty()) {
            //     return "0";
            // }
            // return res;

            int lena = a.length();
            int lenb = b.length();
            int len = max(lena, lenb);
            int carry = 0;
            int i = len - 1;
            string res(len, 0);
            a.insert(0, string(len - lena, 0));
            b.insert(0, string(len - lenb, 0));

            for (; i >= 0; i--) {
                if (a[i] == '1') {
                    carry += 1;
                }
                if (b[i] == '1') {
                    carry += 1;
                }
                res[i] = carry % 2 + '0';
                carry /= 2;
            }
            if (carry == 1) {
                res.insert(0, "1");
                return res;
            }
            res.erase(0, res.find_first_not_of('0'));
            if (res.empty()) {
                return "0";
            }
            return res;
        }
};
